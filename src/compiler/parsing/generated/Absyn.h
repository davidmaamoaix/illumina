#ifndef ABSYN_HEADER
#define ABSYN_HEADER

/* C++ Abstract Syntax Interface generated by the BNF Converter.*/

/********************   TypeDef Section    ********************/

typedef int Integer;
typedef char Char;
typedef double Double;
typedef char* String;
typedef char* Ident;
typedef char* Iden;

/********************   Forward Declarations    ***********************/

struct ListIden_;
typedef struct ListIden_ *ListIden;

struct ListGlobDecl_;
typedef struct ListGlobDecl_ *ListGlobDecl;

struct ListPack_;
typedef struct ListPack_ *ListPack;

struct ListClassMemDecl_;
typedef struct ListClassMemDecl_ *ListClassMemDecl;

struct ListTypeArg_;
typedef struct ListTypeArg_ *ListTypeArg;

struct ListParaSig_;
typedef struct ListParaSig_ *ListParaSig;

struct ListProp_;
typedef struct ListProp_ *ListProp;

struct ListPropDecl_;
typedef struct ListPropDecl_ *ListPropDecl;

struct ListCType_;
typedef struct ListCType_ *ListCType;

struct ListType_;
typedef struct ListType_ *ListType;

struct ListStmt_;
typedef struct ListStmt_ *ListStmt;

struct ListExp_;
typedef struct ListExp_ *ListExp;

struct Program_;
typedef struct Program_ *Program;

struct GlobDecl_;
typedef struct GlobDecl_ *GlobDecl;

struct ImportDecl_;
typedef struct ImportDecl_ *ImportDecl;

struct Pack_;
typedef struct Pack_ *Pack;

struct ClassMemDecl_;
typedef struct ClassMemDecl_ *ClassMemDecl;

struct TypeArg_;
typedef struct TypeArg_ *TypeArg;

struct TArgsDecl_;
typedef struct TArgsDecl_ *TArgsDecl;

struct FuncDecl_;
typedef struct FuncDecl_ *FuncDecl;

struct FuncBody_;
typedef struct FuncBody_ *FuncBody;

struct ParaSig_;
typedef struct ParaSig_ *ParaSig;

struct ClassDecl_;
typedef struct ClassDecl_ *ClassDecl;

struct Inhrt_;
typedef struct Inhrt_ *Inhrt;

struct Prop_;
typedef struct Prop_ *Prop;

struct PropDecl_;
typedef struct PropDecl_ *PropDecl;

struct VarSig_;
typedef struct VarSig_ *VarSig;

struct VarDef_;
typedef struct VarDef_ *VarDef;

struct GVarDef_;
typedef struct GVarDef_ *GVarDef;

struct CType_;
typedef struct CType_ *CType;

struct Type_;
typedef struct Type_ *Type;

struct Lit_;
typedef struct Lit_ *Lit;

struct Op_;
typedef struct Op_ *Op;

struct Stmt_;
typedef struct Stmt_ *Stmt;

struct Else_;
typedef struct Else_ *Else;

struct StmtBlock_;
typedef struct StmtBlock_ *StmtBlock;

struct Exp_;
typedef struct Exp_ *Exp;

struct OptionExp_;
typedef struct OptionExp_ *OptionExp;

struct LamBody_;
typedef struct LamBody_ *LamBody;

/********************   Abstract Syntax Classes    ********************/

struct ListIden_
{
    Iden iden_;
    ListIden listiden_;
};

ListIden make_ListIden(Iden p1, ListIden p2);

struct Program_
{
    enum { is_Prog } kind;
    union
    {
        struct { ListGlobDecl listglobdecl_; } prog_;
    } u;
};

Program make_Prog(ListGlobDecl p0);

struct GlobDecl_
{
    enum { is_GMemDecl, is_GClassDecl, is_GImport } kind;
    union
    {
        struct { ClassMemDecl classmemdecl_; } gmemdecl_;
        struct { ClassDecl classdecl_; } gclassdecl_;
        struct { ImportDecl importdecl_; } gimport_;
    } u;
};

GlobDecl make_GMemDecl(ClassMemDecl p0);
GlobDecl make_GClassDecl(ClassDecl p0);
GlobDecl make_GImport(ImportDecl p0);

struct ListGlobDecl_
{
    GlobDecl globdecl_;
    ListGlobDecl listglobdecl_;
};

ListGlobDecl make_ListGlobDecl(GlobDecl p1, ListGlobDecl p2);

struct ImportDecl_
{
    enum { is_IImport } kind;
    union
    {
        struct { ListPack listpack_; ListPropDecl listpropdecl_; } iimport_;
    } u;
};

ImportDecl make_IImport(ListPropDecl p0, ListPack p1);

struct Pack_
{
    enum { is_PackName } kind;
    union
    {
        struct { Iden iden_; } packname_;
    } u;
};

Pack make_PackName(Iden p0);

struct ListPack_
{
    Pack pack_;
    ListPack listpack_;
};

ListPack make_ListPack(Pack p1, ListPack p2);

struct ClassMemDecl_
{
    enum { is_CVarDecl, is_CFuncDecl } kind;
    union
    {
        struct { GVarDef gvardef_; } cvardecl_;
        struct { FuncDecl funcdecl_; } cfuncdecl_;
    } u;
};

ClassMemDecl make_CVarDecl(GVarDef p0);
ClassMemDecl make_CFuncDecl(FuncDecl p0);

struct ListClassMemDecl_
{
    ClassMemDecl classmemdecl_;
    ListClassMemDecl listclassmemdecl_;
};

ListClassMemDecl make_ListClassMemDecl(ClassMemDecl p1, ListClassMemDecl p2);

struct TypeArg_
{
    enum { is_TSimp, is_TCov, is_TContra } kind;
    union
    {
        struct { Iden iden_; } tsimp_;
        struct { Iden iden_; Type type_; } tcov_;
        struct { Iden iden_; Type type_; } tcontra_;
    } u;
};

TypeArg make_TSimp(Iden p0);
TypeArg make_TCov(Iden p0, Type p1);
TypeArg make_TContra(Iden p0, Type p1);

struct ListTypeArg_
{
    TypeArg typearg_;
    ListTypeArg listtypearg_;
};

ListTypeArg make_ListTypeArg(TypeArg p1, ListTypeArg p2);

struct TArgsDecl_
{
    enum { is_TNil, is_TDecl } kind;
    union
    {
        struct { ListTypeArg listtypearg_; } tdecl_;
    } u;
};

TArgsDecl make_TNil(void);
TArgsDecl make_TDecl(ListTypeArg p0);

struct FuncDecl_
{
    enum { is_FFunc } kind;
    union
    {
        struct { FuncBody funcbody_; Iden iden_; ListParaSig listparasig_; ListPropDecl listpropdecl_; TArgsDecl targsdecl_; Type type_; } ffunc_;
    } u;
};

FuncDecl make_FFunc(ListPropDecl p0, Iden p1, TArgsDecl p2, ListParaSig p3, Type p4, FuncBody p5);

struct FuncBody_
{
    enum { is_FAbsBody, is_FConBody } kind;
    union
    {
        struct { StmtBlock stmtblock_; } fconbody_;
    } u;
};

FuncBody make_FAbsBody(void);
FuncBody make_FConBody(StmtBlock p0);

struct ParaSig_
{
    enum { is_PSig } kind;
    union
    {
        struct { Iden iden_; Type type_; } psig_;
    } u;
};

ParaSig make_PSig(Iden p0, Type p1);

struct ListParaSig_
{
    ParaSig parasig_;
    ListParaSig listparasig_;
};

ListParaSig make_ListParaSig(ParaSig p1, ListParaSig p2);

struct ClassDecl_
{
    enum { is_CClass, is_CInter } kind;
    union
    {
        struct { Iden iden_; Inhrt inhrt_; ListClassMemDecl listclassmemdecl_; ListPropDecl listpropdecl_; TArgsDecl targsdecl_; } cclass_;
        struct { Iden iden_; Inhrt inhrt_; ListClassMemDecl listclassmemdecl_; ListPropDecl listpropdecl_; TArgsDecl targsdecl_; } cinter_;
    } u;
};

ClassDecl make_CClass(ListPropDecl p0, Iden p1, TArgsDecl p2, Inhrt p3, ListClassMemDecl p4);
ClassDecl make_CInter(ListPropDecl p0, TArgsDecl p1, Iden p2, Inhrt p3, ListClassMemDecl p4);

struct Inhrt_
{
    enum { is_INoInherit, is_IInherit } kind;
    union
    {
        struct { ListCType listctype_; } iinherit_;
    } u;
};

Inhrt make_INoInherit(void);
Inhrt make_IInherit(ListCType p0);

struct Prop_
{
    enum { is_PName } kind;
    union
    {
        struct { Iden iden_; } pname_;
    } u;
};

Prop make_PName(Iden p0);

struct PropDecl_
{
    enum { is_PProp } kind;
    union
    {
        struct { ListProp listprop_; } pprop_;
    } u;
};

PropDecl make_PProp(ListProp p0);

struct ListProp_
{
    Prop prop_;
    ListProp listprop_;
};

ListProp make_ListProp(Prop p1, ListProp p2);

struct ListPropDecl_
{
    PropDecl propdecl_;
    ListPropDecl listpropdecl_;
};

ListPropDecl make_ListPropDecl(PropDecl p1, ListPropDecl p2);

struct VarSig_
{
    enum { is_VSig } kind;
    union
    {
        struct { ListIden listiden_; Type type_; } vsig_;
    } u;
};

VarSig make_VSig(ListIden p0, Type p1);

struct VarDef_
{
    enum { is_VNoAsn, is_VAsn } kind;
    union
    {
        struct { VarSig varsig_; } vnoasn_;
        struct { ListExp listexp_; VarSig varsig_; } vasn_;
    } u;
};

VarDef make_VNoAsn(VarSig p0);
VarDef make_VAsn(VarSig p0, ListExp p1);

struct GVarDef_
{
    enum { is_MPropVar } kind;
    union
    {
        struct { ListPropDecl listpropdecl_; VarDef vardef_; } mpropvar_;
    } u;
};

GVarDef make_MPropVar(ListPropDecl p0, VarDef p1);

struct CType_
{
    enum { is_CSimp, is_CGen, is_CList, is_CTup } kind;
    union
    {
        struct { Iden iden_; } csimp_;
        struct { Iden iden_; ListType listtype_; } cgen_;
        struct { Type type_; } clist_;
        struct { ListType listtype_; } ctup_;
    } u;
};

CType make_CSimp(Iden p0);
CType make_CGen(Iden p0, ListType p1);
CType make_CList(Type p0);
CType make_CTup(ListType p0);

struct ListCType_
{
    CType ctype_;
    ListCType listctype_;
};

ListCType make_ListCType(CType p1, ListCType p2);

struct Type_
{
    enum { is_TMaybe, is_TPure } kind;
    union
    {
        struct { CType ctype_; } tmaybe_;
        struct { CType ctype_; } tpure_;
    } u;
};

Type make_TMaybe(CType p0);
Type make_TPure(CType p0);

struct ListType_
{
    Type type_;
    ListType listtype_;
};

ListType make_ListType(Type p1, ListType p2);

struct Lit_
{
    enum { is_LInt, is_LStr, is_LChr, is_LFlo } kind;
    union
    {
        struct { Integer integer_; } lint_;
        struct { String string_; } lstr_;
        struct { Char char_; } lchr_;
        struct { Double double_; } lflo_;
    } u;
};

Lit make_LInt(Integer p0);
Lit make_LStr(String p0);
Lit make_LChr(Char p0);
Lit make_LFlo(Double p0);

struct Op_
{
    enum { is_Asn, is_AddAsn, is_SubAsn, is_MulAsn, is_DivAsn, is_ModAsn, is_AndAsn, is_XorAsn, is_OrAsn, is_ShlAsn, is_ShrAsn, is_LogOr, is_LogAnd, is_BitOr, is_BitXor, is_BitAnd, is_NotEq, is_Eq, is_Lt, is_Gt, is_Leq, is_Geq, is_Shl, is_Shr, is_Add, is_Sub, is_Mul, is_Div, is_Mod, is_Pow, is_Ref } kind;
    union
    {
    } u;
};

Op make_Asn(void);
Op make_AddAsn(void);
Op make_SubAsn(void);
Op make_MulAsn(void);
Op make_DivAsn(void);
Op make_ModAsn(void);
Op make_AndAsn(void);
Op make_XorAsn(void);
Op make_OrAsn(void);
Op make_ShlAsn(void);
Op make_ShrAsn(void);
Op make_LogOr(void);
Op make_LogAnd(void);
Op make_BitOr(void);
Op make_BitXor(void);
Op make_BitAnd(void);
Op make_NotEq(void);
Op make_Eq(void);
Op make_Lt(void);
Op make_Gt(void);
Op make_Leq(void);
Op make_Geq(void);
Op make_Shl(void);
Op make_Shr(void);
Op make_Add(void);
Op make_Sub(void);
Op make_Mul(void);
Op make_Div(void);
Op make_Mod(void);
Op make_Pow(void);
Op make_Ref(void);

struct Stmt_
{
    enum { is_SExp, is_SDecl, is_SRetNil, is_SRet, is_SBreak, is_SCont, is_SIf, is_SFor, is_SWhile } kind;
    union
    {
        struct { Exp exp_; } sexp_;
        struct { VarDef vardef_; } sdecl_;
        struct { Exp exp_; } sret_;
        struct { Else else_; Exp exp_; StmtBlock stmtblock_; } sif_;
        struct { Exp exp_; Iden iden_; StmtBlock stmtblock_; } sfor_;
        struct { Exp exp_; StmtBlock stmtblock_; } swhile_;
    } u;
};

Stmt make_SExp(Exp p0);
Stmt make_SDecl(VarDef p0);
Stmt make_SRetNil(void);
Stmt make_SRet(Exp p0);
Stmt make_SBreak(void);
Stmt make_SCont(void);
Stmt make_SIf(Exp p0, StmtBlock p1, Else p2);
Stmt make_SFor(Iden p0, Exp p1, StmtBlock p2);
Stmt make_SWhile(Exp p0, StmtBlock p1);

struct Else_
{
    enum { is_EEmpty, is_EElse } kind;
    union
    {
        struct { StmtBlock stmtblock_; } eelse_;
    } u;
};

Else make_EEmpty(void);
Else make_EElse(StmtBlock p0);

struct ListStmt_
{
    Stmt stmt_;
    ListStmt liststmt_;
};

ListStmt make_ListStmt(Stmt p1, ListStmt p2);

struct StmtBlock_
{
    enum { is_SStmt } kind;
    union
    {
        struct { ListStmt liststmt_; } sstmt_;
    } u;
};

StmtBlock make_SStmt(ListStmt p0);

struct Exp_
{
    enum { is_EOp, is_PreInc, is_PreDec, is_Pos, is_Neg, is_LogNot, is_BitNot, is_SufInc, is_SufDec, is_ArrIdx, is_FuncCall, is_ELit, is_EIde, is_ENil, is_ESing, is_EMore, is_ETupOne, is_ETupTwo, is_EList } kind;
    union
    {
        struct { Exp exp_1, exp_2; Op op_; } eop_;
        struct { Exp exp_; } preinc_;
        struct { Exp exp_; } predec_;
        struct { Exp exp_; } pos_;
        struct { Exp exp_; } neg_;
        struct { Exp exp_; } lognot_;
        struct { Exp exp_; } bitnot_;
        struct { Exp exp_; } sufinc_;
        struct { Exp exp_; } sufdec_;
        struct { Exp exp_1, exp_2; } arridx_;
        struct { Exp exp_; ListExp listexp_; } funccall_;
        struct { Lit lit_; } elit_;
        struct { Iden iden_; } eide_;
        struct { Iden iden_; LamBody lambody_; } esing_;
        struct { LamBody lambody_; ListIden listiden_; } emore_;
        struct { Exp exp_; } etupone_;
        struct { Exp exp_1, exp_2; OptionExp optionexp_; } etuptwo_;
        struct { ListExp listexp_; } elist_;
    } u;
};

Exp make_EOp(Exp p0, Op p1, Exp p2);
Exp make_PreInc(Exp p0);
Exp make_PreDec(Exp p0);
Exp make_Pos(Exp p0);
Exp make_Neg(Exp p0);
Exp make_LogNot(Exp p0);
Exp make_BitNot(Exp p0);
Exp make_SufInc(Exp p0);
Exp make_SufDec(Exp p0);
Exp make_ArrIdx(Exp p0, Exp p1);
Exp make_FuncCall(Exp p0, ListExp p1);
Exp make_ELit(Lit p0);
Exp make_EIde(Iden p0);
Exp make_ENil(void);
Exp make_ESing(Iden p0, LamBody p1);
Exp make_EMore(ListIden p0, LamBody p1);
Exp make_ETupOne(Exp p0);
Exp make_ETupTwo(Exp p0, Exp p1, OptionExp p2);
Exp make_EList(ListExp p0);

struct ListExp_
{
    Exp exp_;
    ListExp listexp_;
};

ListExp make_ListExp(Exp p1, ListExp p2);

struct OptionExp_
{
    enum { is_ONil, is_OExp } kind;
    union
    {
        struct { ListExp listexp_; } oexp_;
    } u;
};

OptionExp make_ONil(void);
OptionExp make_OExp(ListExp p0);

struct LamBody_
{
    enum { is_LExp } kind;
    union
    {
        struct { Exp exp_; } lexp_;
    } u;
};

LamBody make_LExp(Exp p0);

/********************   Defined Constructors    ***********************/

#define make_opf(a,o,b) make_EOp(a,o,b)

#endif
