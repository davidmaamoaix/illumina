#include "file_loader.h"

#include <stdlib.h>

#include "common/logging.h"
#include "runtime/structure/name_table.h"

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
    uint16_t name_table_size = stream_read_2(stream);
    name_table_init(name_table_size, &object_file->name_table);

    for (int i = 0; i < name_table_size; ++i) {
        uint16_t name_length = stream_read_2(stream);

        object_file->name_table.names[i] = stream_read_str(stream, name_length);
    }

    return object_file;
}