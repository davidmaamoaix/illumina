#include "AST.h"

#include "common/util/assert.h"
#include "common/prelude/prelude_type_path.h"
#include "compiler/compiler_state.h"

typedef struct {
    Iden iden_;
    Inhrt inhrt_;
    ListClassMemDecl listclassmemdecl_;
    ListPropDecl listpropdecl_;
    TArgsDecl targsdecl_;
} raw_class_t;

#define AST_TRANS(header, cont)\
    program_t *(header) {\
        program_t *node = malloc(sizeof(program_t));\
        ASSERT_MALLOC(node);\
        cont\
        return node;\
    }

/*
 * 'out': (initialized) output array ptr
 */
#define UNLIST(out, lst, lst_type, elem_field, nxt_field, map_func)\
    do {\
        lst_type curr = (lst);\
        while (curr != NULL) {\
            void *val = map_func(curr->elem_field);\
            g_array_append_val(out, val);\
            curr = curr->nxt_field;\
        }\
    } while (0)

#define ERR_BAD_ENUM COMPILER_SET_ERRNO(SANITY_CHECK, "Inexhausive enum switch")
#define UN_IDEN(x) (strdup((x)->u.packname_.iden_))
#define NEW_NODE_ARRAY g_array_new(FALSE, FALSE, sizeof(program_t *))

void ast_free_node(program_t *node) {

}

AST_TRANS(gen_ast(Program program), {
    node->kind = PROGRAM;
    node->val.program.imports = NEW_NODE_ARRAY;
    node->val.program.classes = NEW_NODE_ARRAY;
    node->val.program.funcs = NEW_NODE_ARRAY;
    node->val.program.vars = NEW_NODE_ARRAY;

    ListGlobDecl curr = program->u.prog_.listglobdecl_;
    while (curr != NULL) {
        GlobDecl decl = curr->globdecl_;
        switch (decl->kind) {
            case is_GMemDecl:
                break;
            case is_GClassDecl: {
                program_t *cls = gen_class_decl(decl->u.gclassdecl_.classdecl_);
                g_array_append_val(node->val.program.classes, cls);
                break;
            }
            case is_GImport: {
                program_t *import = gen_import(decl->u.gimport_.importdecl_);
                g_array_append_val(node->val.program.imports, import);
                break;
            }
            default:
                ERR_BAD_ENUM;
                ast_free_node(node);
                return NULL;
        }

        curr = curr->listglobdecl_;
    }
})

AST_TRANS(gen_import(ImportDecl decl), {
    node->kind = IMPORT;
    node->val.import.attrs = 0;
    node->val.import.pkgs = g_array_new(FALSE, FALSE, sizeof(char *));

    UNLIST(
        node->val.import.pkgs, decl->u.iimport_.listpack_,
        ListPack, pack_, listpack_, UN_IDEN
    );
})

// TODO
AST_TRANS(gen_class_decl(ClassDecl decl), {
    node->kind = DECL_CLASS;
    node->val.decl_class.inhrt = NEW_NODE_ARRAY;
    node->val.decl_class.targs = NEW_NODE_ARRAY;
    node->val.decl_class.vars = NEW_NODE_ARRAY;
    node->val.decl_class.funcs = NEW_NODE_ARRAY;

    raw_class_t *data;
    switch (decl->kind) {
        case is_CClass:
            data = (raw_class_t *) &decl->u.cclass_;
            break;
        case is_CInter:
            node->val.decl_class.attrs |= 1;
            data = (raw_class_t *) &decl->u.cinter_;
            break;
        default:
            ERR_BAD_ENUM;
            ast_free_node(node);
            return NULL;
    }

    node->val.decl_class.iden = strdup(data->iden_);
})

program_t *gen_type(Type decl) {
    switch (decl->kind) {
        case is_TMaybe:
            return gen_type_con(decl->u.tmaybe_.ctype_, TRUE);
        case is_TPure:
            return gen_type_con(decl->u.tpure_.ctype_, FALSE);
        default:
            ERR_BAD_ENUM;
            return NULL;
    }
}

AST_TRANS(gen_type_con(CType decl, bool nullable), {
    switch (decl->kind) {
        case is_CSimp:
            node->kind = T_SIMP;
            node->val.type_simp.nullable = nullable;
            node->val.type_simp.iden = decl->u.csimp_.iden_;
            break;
        case is_CList:
            node->kind = T_COMP;
            node->val.type_comp.iden = TPATH_LIST;
            node->val.type_comp.nullable = nullable;
            node->val.type_comp.params = NEW_NODE_ARRAY;
            program_t *inner = gen_type(decl->u.clist_.type_);
            g_array_append_val(node->val.type_comp.params, inner);
            break;
        case is_CGen:
            node->kind = T_COMP;
            node->val.type_comp.iden = strdup(decl->u.cgen_.iden_);
            node->val.type_comp.nullable = nullable;
            node->val.type_comp.params = NEW_NODE_ARRAY;
            UNLIST(
                node->val.type_comp.params, decl->u.ctup_.listtype_, ListType,
                type_, listtype_, gen_type
            );
            break;
        case is_CTup:
            node->kind = T_COMP;
            node->val.type_comp.iden = TPATH_TUPLE;
            node->val.type_comp.nullable = nullable;
            node->val.type_comp.params = NEW_NODE_ARRAY;
            UNLIST(
                node->val.type_comp.params, decl->u.ctup_.listtype_, ListType,
                type_, listtype_, gen_type
            );
            break;
        default:
            ERR_BAD_ENUM;
            ast_free_node(node);
            return NULL;
    }
})

AST_TRANS(gen_targs_decl(TArgsDecl decl), {

})

AST_TRANS(gen_func_decl(FuncDecl decl), {
    node->kind = DECL_FUNC;
})

AST_TRANS(gen_gval_decl(GVarDef decl), {
    node->kind = DECL_GVAR;
})

AST_TRANS(gen_exp(Exp exp), {

})
