#include "file_loader.h"

#include <stdlib.h>

#include "common/logging.h"
#include "runtime/structure/link_table.h"

void file_name_table_init(NAME_TABLE_SIZE_T size, file_name_table_t *table) {
    table->size = size;
    table->names = malloc(size * sizeof(char *));
}

void file_name_table_release(file_name_table_t *table) {
    for (int i = 0; i < table->size; ++i) {
        free(table->names[i]);
    }

    free(table->names);
}

void file_linker_init(POOL_SIZE_T size, file_linker_t *linker) {
    linker->size = size;
    linker->links = malloc(size * sizeof(file_linker_ref_t));
}

void file_linker_release(file_linker_t *linker) {
    free(linker->links);
}

void file_linker_load_entry(file_linker_ref_t *entry, stream_t *stream) {
    entry->tag = stream_read_1(stream);

    switch (entry->tag) {
        case LINK_TYPE_INT:
        case LINK_TYPE_FLOAT:
        case LINK_TYPE_GLOBAL_VAR:
        case LINK_TYPE_FIELD_REF:
            entry->value = stream_read_4(stream);
            entry->extra = stream_read_4(stream);
            break;

        case LINK_TYPE_STRING:
        case LINK_TYPE_FUNCTION:
        case LINK_TYPE_CLASS:
            entry->value = stream_read_4(stream);
            break;

        default:
            VM_SET_THREAD_ERRNO(VM_ERRNO_BAD_FILE_FORMAT);
            return;
    }
}

void file_class_pool_init(POOL_SIZE_T size, file_class_pool_t *pool) {
    pool->size = size;
    pool->classes = malloc(size * sizeof(file_class_pool_t));
}

void file_class_pool_release(file_class_pool_t * pool) {
    free(pool->classes);
}

void file_class_pool_load_entry(file_class_t *entry, stream_t *stream) {

}

file_rep_t *load_file_rep(stream_t *stream) {
    file_rep_t *object_file = malloc(sizeof(file_rep_t));

    // header
    if (stream_read_4(stream) != 0xABCDDCBA) {
        ERROR("Invalid object file signature (expected 0xABCDDCBA)");
        VM_SET_THREAD_ERRNO(VM_ERRNO_BAD_FILE_FORMAT);
        return object_file;
    }

    stream_read_4(stream);
    stream_read_8(stream);

    // name table
    NAME_TABLE_SIZE_T name_table_size = stream_read_4(stream);
    file_name_table_init(name_table_size, &object_file->name_table);

    for (int i = 0; i < name_table_size; ++i) {
        uint16_t name_length = stream_read_2(stream);

        object_file->name_table.names[i] = stream_read_str(stream, name_length);
    }

    VM_GOTO_IF_ERROR(error_name_table);

    // link table
    POOL_SIZE_T link_table_size = stream_read_4(stream);
    file_linker_init(link_table_size, &object_file->link_table);

    for (int i = 0; i < link_table_size; ++i) {
        file_linker_load_entry(&object_file->link_table.links[i], stream);
    }

    VM_GOTO_IF_ERROR(error_linker);

    // end of structure setup

    // classes
    POOL_SIZE_T class_pool_size = stream_read_4(stream);
    file_class_pool_init(class_pool_size, &object_file->class_pool);

    if (stream->pc != stream->end) {
        VM_SET_THREAD_ERRNO(VM_ERRNO_BAD_FILE_FORMAT);
    }

    VM_GOTO_IF_ERROR(error_class_pool);

    return object_file;

    error_class_pool:
    file_class_pool_release(&object_file->class_pool);

    error_linker:
    file_linker_release(&object_file->link_table);

    error_name_table:
    file_name_table_release(&object_file->name_table);

    free(object_file);
    return NULL;
}