/* C Abstract Syntax Implementation generated by the BNF Converter. */

#include <stdio.h>
#include <stdlib.h>
#include "Absyn.h"

/********************   ListIden    ********************/

ListIden make_ListIden(Iden p1, ListIden p2)
{
    ListIden tmp = (ListIden) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating ListIden!\n");
        exit(1);
    }
    tmp->iden_ = p1;
    tmp->listiden_ = p2;
    return tmp;
}

/********************   Prog    ********************/

Program make_Prog(ListGlobDecl p1)
{
    Program tmp = (Program) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating Prog!\n");
        exit(1);
    }
    tmp->kind = is_Prog;
    tmp->u.prog_.listglobdecl_ = p1;
    return tmp;
}

/********************   GMemDecl    ********************/

GlobDecl make_GMemDecl(ClassMemDecl p1)
{
    GlobDecl tmp = (GlobDecl) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating GMemDecl!\n");
        exit(1);
    }
    tmp->kind = is_GMemDecl;
    tmp->u.gmemdecl_.classmemdecl_ = p1;
    return tmp;
}

/********************   GClassDecl    ********************/

GlobDecl make_GClassDecl(ClassDecl p1)
{
    GlobDecl tmp = (GlobDecl) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating GClassDecl!\n");
        exit(1);
    }
    tmp->kind = is_GClassDecl;
    tmp->u.gclassdecl_.classdecl_ = p1;
    return tmp;
}

/********************   GImport    ********************/

GlobDecl make_GImport(ImportDecl p1)
{
    GlobDecl tmp = (GlobDecl) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating GImport!\n");
        exit(1);
    }
    tmp->kind = is_GImport;
    tmp->u.gimport_.importdecl_ = p1;
    return tmp;
}

/********************   ListGlobDecl    ********************/

ListGlobDecl make_ListGlobDecl(GlobDecl p1, ListGlobDecl p2)
{
    ListGlobDecl tmp = (ListGlobDecl) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating ListGlobDecl!\n");
        exit(1);
    }
    tmp->globdecl_ = p1;
    tmp->listglobdecl_ = p2;
    return tmp;
}

/********************   IImport    ********************/

ImportDecl make_IImport(ListPropDecl p1, ListPack p2)
{
    ImportDecl tmp = (ImportDecl) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating IImport!\n");
        exit(1);
    }
    tmp->kind = is_IImport;
    tmp->u.iimport_.listpropdecl_ = p1;
    tmp->u.iimport_.listpack_ = p2;
    return tmp;
}

/********************   PackName    ********************/

Pack make_PackName(Iden p1)
{
    Pack tmp = (Pack) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating PackName!\n");
        exit(1);
    }
    tmp->kind = is_PackName;
    tmp->u.packname_.iden_ = p1;
    return tmp;
}

/********************   ListPack    ********************/

ListPack make_ListPack(Pack p1, ListPack p2)
{
    ListPack tmp = (ListPack) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating ListPack!\n");
        exit(1);
    }
    tmp->pack_ = p1;
    tmp->listpack_ = p2;
    return tmp;
}

/********************   CVarDecl    ********************/

ClassMemDecl make_CVarDecl(GVarDef p1)
{
    ClassMemDecl tmp = (ClassMemDecl) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating CVarDecl!\n");
        exit(1);
    }
    tmp->kind = is_CVarDecl;
    tmp->u.cvardecl_.gvardef_ = p1;
    return tmp;
}

/********************   CFuncDecl    ********************/

ClassMemDecl make_CFuncDecl(FuncDecl p1)
{
    ClassMemDecl tmp = (ClassMemDecl) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating CFuncDecl!\n");
        exit(1);
    }
    tmp->kind = is_CFuncDecl;
    tmp->u.cfuncdecl_.funcdecl_ = p1;
    return tmp;
}

/********************   ListClassMemDecl    ********************/

ListClassMemDecl make_ListClassMemDecl(ClassMemDecl p1, ListClassMemDecl p2)
{
    ListClassMemDecl tmp = (ListClassMemDecl) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating ListClassMemDecl!\n");
        exit(1);
    }
    tmp->classmemdecl_ = p1;
    tmp->listclassmemdecl_ = p2;
    return tmp;
}

/********************   TSimp    ********************/

TypeArg make_TSimp(Iden p1)
{
    TypeArg tmp = (TypeArg) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating TSimp!\n");
        exit(1);
    }
    tmp->kind = is_TSimp;
    tmp->u.tsimp_.iden_ = p1;
    return tmp;
}

/********************   TCov    ********************/

TypeArg make_TCov(Iden p1, Type p2)
{
    TypeArg tmp = (TypeArg) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating TCov!\n");
        exit(1);
    }
    tmp->kind = is_TCov;
    tmp->u.tcov_.iden_ = p1;
    tmp->u.tcov_.type_ = p2;
    return tmp;
}

/********************   TContra    ********************/

TypeArg make_TContra(Iden p1, Type p2)
{
    TypeArg tmp = (TypeArg) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating TContra!\n");
        exit(1);
    }
    tmp->kind = is_TContra;
    tmp->u.tcontra_.iden_ = p1;
    tmp->u.tcontra_.type_ = p2;
    return tmp;
}

/********************   ListTypeArg    ********************/

ListTypeArg make_ListTypeArg(TypeArg p1, ListTypeArg p2)
{
    ListTypeArg tmp = (ListTypeArg) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating ListTypeArg!\n");
        exit(1);
    }
    tmp->typearg_ = p1;
    tmp->listtypearg_ = p2;
    return tmp;
}

/********************   TNil    ********************/

TArgsDecl make_TNil()
{
    TArgsDecl tmp = (TArgsDecl) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating TNil!\n");
        exit(1);
    }
    tmp->kind = is_TNil;
    return tmp;
}

/********************   TDecl    ********************/

TArgsDecl make_TDecl(ListTypeArg p1)
{
    TArgsDecl tmp = (TArgsDecl) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating TDecl!\n");
        exit(1);
    }
    tmp->kind = is_TDecl;
    tmp->u.tdecl_.listtypearg_ = p1;
    return tmp;
}

/********************   FFunc    ********************/

FuncDecl make_FFunc(ListPropDecl p1, Iden p2, TArgsDecl p3, ListParaSig p4, Type p5, FuncBody p6)
{
    FuncDecl tmp = (FuncDecl) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating FFunc!\n");
        exit(1);
    }
    tmp->kind = is_FFunc;
    tmp->u.ffunc_.listpropdecl_ = p1;
    tmp->u.ffunc_.iden_ = p2;
    tmp->u.ffunc_.targsdecl_ = p3;
    tmp->u.ffunc_.listparasig_ = p4;
    tmp->u.ffunc_.type_ = p5;
    tmp->u.ffunc_.funcbody_ = p6;
    return tmp;
}

/********************   FAbsBody    ********************/

FuncBody make_FAbsBody()
{
    FuncBody tmp = (FuncBody) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating FAbsBody!\n");
        exit(1);
    }
    tmp->kind = is_FAbsBody;
    return tmp;
}

/********************   FConBody    ********************/

FuncBody make_FConBody(StmtBlock p1)
{
    FuncBody tmp = (FuncBody) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating FConBody!\n");
        exit(1);
    }
    tmp->kind = is_FConBody;
    tmp->u.fconbody_.stmtblock_ = p1;
    return tmp;
}

/********************   PSig    ********************/

ParaSig make_PSig(Iden p1, Type p2)
{
    ParaSig tmp = (ParaSig) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating PSig!\n");
        exit(1);
    }
    tmp->kind = is_PSig;
    tmp->u.psig_.iden_ = p1;
    tmp->u.psig_.type_ = p2;
    return tmp;
}

/********************   ListParaSig    ********************/

ListParaSig make_ListParaSig(ParaSig p1, ListParaSig p2)
{
    ListParaSig tmp = (ListParaSig) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating ListParaSig!\n");
        exit(1);
    }
    tmp->parasig_ = p1;
    tmp->listparasig_ = p2;
    return tmp;
}

/********************   CClass    ********************/

ClassDecl make_CClass(ListPropDecl p1, Iden p2, TArgsDecl p3, Inhrt p4, ListClassMemDecl p5)
{
    ClassDecl tmp = (ClassDecl) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating CClass!\n");
        exit(1);
    }
    tmp->kind = is_CClass;
    tmp->u.cclass_.listpropdecl_ = p1;
    tmp->u.cclass_.iden_ = p2;
    tmp->u.cclass_.targsdecl_ = p3;
    tmp->u.cclass_.inhrt_ = p4;
    tmp->u.cclass_.listclassmemdecl_ = p5;
    return tmp;
}

/********************   CInter    ********************/

ClassDecl make_CInter(ListPropDecl p1, TArgsDecl p2, Iden p3, Inhrt p4, ListClassMemDecl p5)
{
    ClassDecl tmp = (ClassDecl) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating CInter!\n");
        exit(1);
    }
    tmp->kind = is_CInter;
    tmp->u.cinter_.listpropdecl_ = p1;
    tmp->u.cinter_.targsdecl_ = p2;
    tmp->u.cinter_.iden_ = p3;
    tmp->u.cinter_.inhrt_ = p4;
    tmp->u.cinter_.listclassmemdecl_ = p5;
    return tmp;
}

/********************   INoInherit    ********************/

Inhrt make_INoInherit()
{
    Inhrt tmp = (Inhrt) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating INoInherit!\n");
        exit(1);
    }
    tmp->kind = is_INoInherit;
    return tmp;
}

/********************   IInherit    ********************/

Inhrt make_IInherit(ListCType p1)
{
    Inhrt tmp = (Inhrt) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating IInherit!\n");
        exit(1);
    }
    tmp->kind = is_IInherit;
    tmp->u.iinherit_.listctype_ = p1;
    return tmp;
}

/********************   PName    ********************/

Prop make_PName(Iden p1)
{
    Prop tmp = (Prop) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating PName!\n");
        exit(1);
    }
    tmp->kind = is_PName;
    tmp->u.pname_.iden_ = p1;
    return tmp;
}

/********************   PProp    ********************/

PropDecl make_PProp(ListProp p1)
{
    PropDecl tmp = (PropDecl) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating PProp!\n");
        exit(1);
    }
    tmp->kind = is_PProp;
    tmp->u.pprop_.listprop_ = p1;
    return tmp;
}

/********************   ListProp    ********************/

ListProp make_ListProp(Prop p1, ListProp p2)
{
    ListProp tmp = (ListProp) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating ListProp!\n");
        exit(1);
    }
    tmp->prop_ = p1;
    tmp->listprop_ = p2;
    return tmp;
}

/********************   ListPropDecl    ********************/

ListPropDecl make_ListPropDecl(PropDecl p1, ListPropDecl p2)
{
    ListPropDecl tmp = (ListPropDecl) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating ListPropDecl!\n");
        exit(1);
    }
    tmp->propdecl_ = p1;
    tmp->listpropdecl_ = p2;
    return tmp;
}

/********************   VSig    ********************/

VarSig make_VSig(ListIden p1, Type p2)
{
    VarSig tmp = (VarSig) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating VSig!\n");
        exit(1);
    }
    tmp->kind = is_VSig;
    tmp->u.vsig_.listiden_ = p1;
    tmp->u.vsig_.type_ = p2;
    return tmp;
}

/********************   VNoAsn    ********************/

VarDef make_VNoAsn(VarSig p1)
{
    VarDef tmp = (VarDef) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating VNoAsn!\n");
        exit(1);
    }
    tmp->kind = is_VNoAsn;
    tmp->u.vnoasn_.varsig_ = p1;
    return tmp;
}

/********************   VAsn    ********************/

VarDef make_VAsn(VarSig p1, ListExp p2)
{
    VarDef tmp = (VarDef) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating VAsn!\n");
        exit(1);
    }
    tmp->kind = is_VAsn;
    tmp->u.vasn_.varsig_ = p1;
    tmp->u.vasn_.listexp_ = p2;
    return tmp;
}

/********************   MPropVar    ********************/

GVarDef make_MPropVar(ListPropDecl p1, VarDef p2)
{
    GVarDef tmp = (GVarDef) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating MPropVar!\n");
        exit(1);
    }
    tmp->kind = is_MPropVar;
    tmp->u.mpropvar_.listpropdecl_ = p1;
    tmp->u.mpropvar_.vardef_ = p2;
    return tmp;
}

/********************   CSimp    ********************/

CType make_CSimp(Iden p1)
{
    CType tmp = (CType) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating CSimp!\n");
        exit(1);
    }
    tmp->kind = is_CSimp;
    tmp->u.csimp_.iden_ = p1;
    return tmp;
}

/********************   CGen    ********************/

CType make_CGen(Iden p1, ListType p2)
{
    CType tmp = (CType) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating CGen!\n");
        exit(1);
    }
    tmp->kind = is_CGen;
    tmp->u.cgen_.iden_ = p1;
    tmp->u.cgen_.listtype_ = p2;
    return tmp;
}

/********************   CList    ********************/

CType make_CList(Type p1)
{
    CType tmp = (CType) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating CList!\n");
        exit(1);
    }
    tmp->kind = is_CList;
    tmp->u.clist_.type_ = p1;
    return tmp;
}

/********************   CTup    ********************/

CType make_CTup(ListType p1)
{
    CType tmp = (CType) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating CTup!\n");
        exit(1);
    }
    tmp->kind = is_CTup;
    tmp->u.ctup_.listtype_ = p1;
    return tmp;
}

/********************   ListCType    ********************/

ListCType make_ListCType(CType p1, ListCType p2)
{
    ListCType tmp = (ListCType) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating ListCType!\n");
        exit(1);
    }
    tmp->ctype_ = p1;
    tmp->listctype_ = p2;
    return tmp;
}

/********************   TMaybe    ********************/

Type make_TMaybe(CType p1)
{
    Type tmp = (Type) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating TMaybe!\n");
        exit(1);
    }
    tmp->kind = is_TMaybe;
    tmp->u.tmaybe_.ctype_ = p1;
    return tmp;
}

/********************   TPure    ********************/

Type make_TPure(CType p1)
{
    Type tmp = (Type) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating TPure!\n");
        exit(1);
    }
    tmp->kind = is_TPure;
    tmp->u.tpure_.ctype_ = p1;
    return tmp;
}

/********************   ListType    ********************/

ListType make_ListType(Type p1, ListType p2)
{
    ListType tmp = (ListType) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating ListType!\n");
        exit(1);
    }
    tmp->type_ = p1;
    tmp->listtype_ = p2;
    return tmp;
}

/********************   LInt    ********************/

Lit make_LInt(Integer p1)
{
    Lit tmp = (Lit) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating LInt!\n");
        exit(1);
    }
    tmp->kind = is_LInt;
    tmp->u.lint_.integer_ = p1;
    return tmp;
}

/********************   LStr    ********************/

Lit make_LStr(String p1)
{
    Lit tmp = (Lit) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating LStr!\n");
        exit(1);
    }
    tmp->kind = is_LStr;
    tmp->u.lstr_.string_ = p1;
    return tmp;
}

/********************   LChr    ********************/

Lit make_LChr(Char p1)
{
    Lit tmp = (Lit) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating LChr!\n");
        exit(1);
    }
    tmp->kind = is_LChr;
    tmp->u.lchr_.char_ = p1;
    return tmp;
}

/********************   LFlo    ********************/

Lit make_LFlo(Double p1)
{
    Lit tmp = (Lit) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating LFlo!\n");
        exit(1);
    }
    tmp->kind = is_LFlo;
    tmp->u.lflo_.double_ = p1;
    return tmp;
}

/********************   Asn    ********************/

Op make_Asn()
{
    Op tmp = (Op) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating Asn!\n");
        exit(1);
    }
    tmp->kind = is_Asn;
    return tmp;
}

/********************   AddAsn    ********************/

Op make_AddAsn()
{
    Op tmp = (Op) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating AddAsn!\n");
        exit(1);
    }
    tmp->kind = is_AddAsn;
    return tmp;
}

/********************   SubAsn    ********************/

Op make_SubAsn()
{
    Op tmp = (Op) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating SubAsn!\n");
        exit(1);
    }
    tmp->kind = is_SubAsn;
    return tmp;
}

/********************   MulAsn    ********************/

Op make_MulAsn()
{
    Op tmp = (Op) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating MulAsn!\n");
        exit(1);
    }
    tmp->kind = is_MulAsn;
    return tmp;
}

/********************   DivAsn    ********************/

Op make_DivAsn()
{
    Op tmp = (Op) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating DivAsn!\n");
        exit(1);
    }
    tmp->kind = is_DivAsn;
    return tmp;
}

/********************   ModAsn    ********************/

Op make_ModAsn()
{
    Op tmp = (Op) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating ModAsn!\n");
        exit(1);
    }
    tmp->kind = is_ModAsn;
    return tmp;
}

/********************   AndAsn    ********************/

Op make_AndAsn()
{
    Op tmp = (Op) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating AndAsn!\n");
        exit(1);
    }
    tmp->kind = is_AndAsn;
    return tmp;
}

/********************   XorAsn    ********************/

Op make_XorAsn()
{
    Op tmp = (Op) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating XorAsn!\n");
        exit(1);
    }
    tmp->kind = is_XorAsn;
    return tmp;
}

/********************   OrAsn    ********************/

Op make_OrAsn()
{
    Op tmp = (Op) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating OrAsn!\n");
        exit(1);
    }
    tmp->kind = is_OrAsn;
    return tmp;
}

/********************   ShlAsn    ********************/

Op make_ShlAsn()
{
    Op tmp = (Op) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating ShlAsn!\n");
        exit(1);
    }
    tmp->kind = is_ShlAsn;
    return tmp;
}

/********************   ShrAsn    ********************/

Op make_ShrAsn()
{
    Op tmp = (Op) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating ShrAsn!\n");
        exit(1);
    }
    tmp->kind = is_ShrAsn;
    return tmp;
}

/********************   LogOr    ********************/

Op make_LogOr()
{
    Op tmp = (Op) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating LogOr!\n");
        exit(1);
    }
    tmp->kind = is_LogOr;
    return tmp;
}

/********************   LogAnd    ********************/

Op make_LogAnd()
{
    Op tmp = (Op) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating LogAnd!\n");
        exit(1);
    }
    tmp->kind = is_LogAnd;
    return tmp;
}

/********************   BitOr    ********************/

Op make_BitOr()
{
    Op tmp = (Op) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating BitOr!\n");
        exit(1);
    }
    tmp->kind = is_BitOr;
    return tmp;
}

/********************   BitXor    ********************/

Op make_BitXor()
{
    Op tmp = (Op) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating BitXor!\n");
        exit(1);
    }
    tmp->kind = is_BitXor;
    return tmp;
}

/********************   BitAnd    ********************/

Op make_BitAnd()
{
    Op tmp = (Op) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating BitAnd!\n");
        exit(1);
    }
    tmp->kind = is_BitAnd;
    return tmp;
}

/********************   NotEq    ********************/

Op make_NotEq()
{
    Op tmp = (Op) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating NotEq!\n");
        exit(1);
    }
    tmp->kind = is_NotEq;
    return tmp;
}

/********************   Eq    ********************/

Op make_Eq()
{
    Op tmp = (Op) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating Eq!\n");
        exit(1);
    }
    tmp->kind = is_Eq;
    return tmp;
}

/********************   Lt    ********************/

Op make_Lt()
{
    Op tmp = (Op) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating Lt!\n");
        exit(1);
    }
    tmp->kind = is_Lt;
    return tmp;
}

/********************   Gt    ********************/

Op make_Gt()
{
    Op tmp = (Op) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating Gt!\n");
        exit(1);
    }
    tmp->kind = is_Gt;
    return tmp;
}

/********************   Leq    ********************/

Op make_Leq()
{
    Op tmp = (Op) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating Leq!\n");
        exit(1);
    }
    tmp->kind = is_Leq;
    return tmp;
}

/********************   Geq    ********************/

Op make_Geq()
{
    Op tmp = (Op) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating Geq!\n");
        exit(1);
    }
    tmp->kind = is_Geq;
    return tmp;
}

/********************   Shl    ********************/

Op make_Shl()
{
    Op tmp = (Op) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating Shl!\n");
        exit(1);
    }
    tmp->kind = is_Shl;
    return tmp;
}

/********************   Shr    ********************/

Op make_Shr()
{
    Op tmp = (Op) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating Shr!\n");
        exit(1);
    }
    tmp->kind = is_Shr;
    return tmp;
}

/********************   Add    ********************/

Op make_Add()
{
    Op tmp = (Op) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating Add!\n");
        exit(1);
    }
    tmp->kind = is_Add;
    return tmp;
}

/********************   Sub    ********************/

Op make_Sub()
{
    Op tmp = (Op) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating Sub!\n");
        exit(1);
    }
    tmp->kind = is_Sub;
    return tmp;
}

/********************   Mul    ********************/

Op make_Mul()
{
    Op tmp = (Op) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating Mul!\n");
        exit(1);
    }
    tmp->kind = is_Mul;
    return tmp;
}

/********************   Div    ********************/

Op make_Div()
{
    Op tmp = (Op) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating Div!\n");
        exit(1);
    }
    tmp->kind = is_Div;
    return tmp;
}

/********************   Mod    ********************/

Op make_Mod()
{
    Op tmp = (Op) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating Mod!\n");
        exit(1);
    }
    tmp->kind = is_Mod;
    return tmp;
}

/********************   Pow    ********************/

Op make_Pow()
{
    Op tmp = (Op) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating Pow!\n");
        exit(1);
    }
    tmp->kind = is_Pow;
    return tmp;
}

/********************   Ref    ********************/

Op make_Ref()
{
    Op tmp = (Op) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating Ref!\n");
        exit(1);
    }
    tmp->kind = is_Ref;
    return tmp;
}

/********************   SExp    ********************/

Stmt make_SExp(Exp p1)
{
    Stmt tmp = (Stmt) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating SExp!\n");
        exit(1);
    }
    tmp->kind = is_SExp;
    tmp->u.sexp_.exp_ = p1;
    return tmp;
}

/********************   SDecl    ********************/

Stmt make_SDecl(VarDef p1)
{
    Stmt tmp = (Stmt) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating SDecl!\n");
        exit(1);
    }
    tmp->kind = is_SDecl;
    tmp->u.sdecl_.vardef_ = p1;
    return tmp;
}

/********************   SRetNil    ********************/

Stmt make_SRetNil()
{
    Stmt tmp = (Stmt) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating SRetNil!\n");
        exit(1);
    }
    tmp->kind = is_SRetNil;
    return tmp;
}

/********************   SRet    ********************/

Stmt make_SRet(Exp p1)
{
    Stmt tmp = (Stmt) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating SRet!\n");
        exit(1);
    }
    tmp->kind = is_SRet;
    tmp->u.sret_.exp_ = p1;
    return tmp;
}

/********************   SBreak    ********************/

Stmt make_SBreak()
{
    Stmt tmp = (Stmt) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating SBreak!\n");
        exit(1);
    }
    tmp->kind = is_SBreak;
    return tmp;
}

/********************   SCont    ********************/

Stmt make_SCont()
{
    Stmt tmp = (Stmt) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating SCont!\n");
        exit(1);
    }
    tmp->kind = is_SCont;
    return tmp;
}

/********************   SIf    ********************/

Stmt make_SIf(AliasIf p1)
{
    Stmt tmp = (Stmt) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating SIf!\n");
        exit(1);
    }
    tmp->kind = is_SIf;
    tmp->u.sif_.aliasif_ = p1;
    return tmp;
}

/********************   SFor    ********************/

Stmt make_SFor(Iden p1, Exp p2, StmtBlock p3)
{
    Stmt tmp = (Stmt) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating SFor!\n");
        exit(1);
    }
    tmp->kind = is_SFor;
    tmp->u.sfor_.iden_ = p1;
    tmp->u.sfor_.exp_ = p2;
    tmp->u.sfor_.stmtblock_ = p3;
    return tmp;
}

/********************   SWhile    ********************/

Stmt make_SWhile(Exp p1, StmtBlock p2)
{
    Stmt tmp = (Stmt) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating SWhile!\n");
        exit(1);
    }
    tmp->kind = is_SWhile;
    tmp->u.swhile_.exp_ = p1;
    tmp->u.swhile_.stmtblock_ = p2;
    return tmp;
}

/********************   EEmpty    ********************/

Else make_EEmpty()
{
    Else tmp = (Else) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating EEmpty!\n");
        exit(1);
    }
    tmp->kind = is_EEmpty;
    return tmp;
}

/********************   EElse    ********************/

Else make_EElse(StmtBlock p1)
{
    Else tmp = (Else) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating EElse!\n");
        exit(1);
    }
    tmp->kind = is_EElse;
    tmp->u.eelse_.stmtblock_ = p1;
    return tmp;
}

/********************   EElif    ********************/

Else make_EElif(AliasIf p1)
{
    Else tmp = (Else) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating EElif!\n");
        exit(1);
    }
    tmp->kind = is_EElif;
    tmp->u.eelif_.aliasif_ = p1;
    return tmp;
}

/********************   AIf    ********************/

AliasIf make_AIf(Exp p1, StmtBlock p2, Else p3)
{
    AliasIf tmp = (AliasIf) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating AIf!\n");
        exit(1);
    }
    tmp->kind = is_AIf;
    tmp->u.aif_.exp_ = p1;
    tmp->u.aif_.stmtblock_ = p2;
    tmp->u.aif_.else_ = p3;
    return tmp;
}

/********************   ListStmt    ********************/

ListStmt make_ListStmt(Stmt p1, ListStmt p2)
{
    ListStmt tmp = (ListStmt) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating ListStmt!\n");
        exit(1);
    }
    tmp->stmt_ = p1;
    tmp->liststmt_ = p2;
    return tmp;
}

/********************   SStmt    ********************/

StmtBlock make_SStmt(ListStmt p1)
{
    StmtBlock tmp = (StmtBlock) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating SStmt!\n");
        exit(1);
    }
    tmp->kind = is_SStmt;
    tmp->u.sstmt_.liststmt_ = p1;
    return tmp;
}

/********************   EOp    ********************/

Exp make_EOp(Exp p1, Op p2, Exp p3)
{
    Exp tmp = (Exp) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating EOp!\n");
        exit(1);
    }
    tmp->kind = is_EOp;
    tmp->u.eop_.exp_1 = p1;
    tmp->u.eop_.op_ = p2;
    tmp->u.eop_.exp_2 = p3;
    return tmp;
}

/********************   PreInc    ********************/

Exp make_PreInc(Exp p1)
{
    Exp tmp = (Exp) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating PreInc!\n");
        exit(1);
    }
    tmp->kind = is_PreInc;
    tmp->u.preinc_.exp_ = p1;
    return tmp;
}

/********************   PreDec    ********************/

Exp make_PreDec(Exp p1)
{
    Exp tmp = (Exp) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating PreDec!\n");
        exit(1);
    }
    tmp->kind = is_PreDec;
    tmp->u.predec_.exp_ = p1;
    return tmp;
}

/********************   Pos    ********************/

Exp make_Pos(Exp p1)
{
    Exp tmp = (Exp) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating Pos!\n");
        exit(1);
    }
    tmp->kind = is_Pos;
    tmp->u.pos_.exp_ = p1;
    return tmp;
}

/********************   Neg    ********************/

Exp make_Neg(Exp p1)
{
    Exp tmp = (Exp) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating Neg!\n");
        exit(1);
    }
    tmp->kind = is_Neg;
    tmp->u.neg_.exp_ = p1;
    return tmp;
}

/********************   LogNot    ********************/

Exp make_LogNot(Exp p1)
{
    Exp tmp = (Exp) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating LogNot!\n");
        exit(1);
    }
    tmp->kind = is_LogNot;
    tmp->u.lognot_.exp_ = p1;
    return tmp;
}

/********************   BitNot    ********************/

Exp make_BitNot(Exp p1)
{
    Exp tmp = (Exp) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating BitNot!\n");
        exit(1);
    }
    tmp->kind = is_BitNot;
    tmp->u.bitnot_.exp_ = p1;
    return tmp;
}

/********************   SufInc    ********************/

Exp make_SufInc(Exp p1)
{
    Exp tmp = (Exp) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating SufInc!\n");
        exit(1);
    }
    tmp->kind = is_SufInc;
    tmp->u.sufinc_.exp_ = p1;
    return tmp;
}

/********************   SufDec    ********************/

Exp make_SufDec(Exp p1)
{
    Exp tmp = (Exp) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating SufDec!\n");
        exit(1);
    }
    tmp->kind = is_SufDec;
    tmp->u.sufdec_.exp_ = p1;
    return tmp;
}

/********************   ArrIdx    ********************/

Exp make_ArrIdx(Exp p1, Exp p2)
{
    Exp tmp = (Exp) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating ArrIdx!\n");
        exit(1);
    }
    tmp->kind = is_ArrIdx;
    tmp->u.arridx_.exp_1 = p1;
    tmp->u.arridx_.exp_2 = p2;
    return tmp;
}

/********************   FuncCall    ********************/

Exp make_FuncCall(Exp p1, TArgsPass p2, ListExp p3)
{
    Exp tmp = (Exp) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating FuncCall!\n");
        exit(1);
    }
    tmp->kind = is_FuncCall;
    tmp->u.funccall_.exp_ = p1;
    tmp->u.funccall_.targspass_ = p2;
    tmp->u.funccall_.listexp_ = p3;
    return tmp;
}

/********************   ELit    ********************/

Exp make_ELit(Lit p1)
{
    Exp tmp = (Exp) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating ELit!\n");
        exit(1);
    }
    tmp->kind = is_ELit;
    tmp->u.elit_.lit_ = p1;
    return tmp;
}

/********************   EIde    ********************/

Exp make_EIde(Iden p1)
{
    Exp tmp = (Exp) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating EIde!\n");
        exit(1);
    }
    tmp->kind = is_EIde;
    tmp->u.eide_.iden_ = p1;
    return tmp;
}

/********************   ENil    ********************/

Exp make_ENil()
{
    Exp tmp = (Exp) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating ENil!\n");
        exit(1);
    }
    tmp->kind = is_ENil;
    return tmp;
}

/********************   ESing    ********************/

Exp make_ESing(Iden p1, LamBody p2)
{
    Exp tmp = (Exp) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating ESing!\n");
        exit(1);
    }
    tmp->kind = is_ESing;
    tmp->u.esing_.iden_ = p1;
    tmp->u.esing_.lambody_ = p2;
    return tmp;
}

/********************   EMore    ********************/

Exp make_EMore(ListIden p1, LamBody p2)
{
    Exp tmp = (Exp) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating EMore!\n");
        exit(1);
    }
    tmp->kind = is_EMore;
    tmp->u.emore_.listiden_ = p1;
    tmp->u.emore_.lambody_ = p2;
    return tmp;
}

/********************   ETupOne    ********************/

Exp make_ETupOne(Exp p1)
{
    Exp tmp = (Exp) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating ETupOne!\n");
        exit(1);
    }
    tmp->kind = is_ETupOne;
    tmp->u.etupone_.exp_ = p1;
    return tmp;
}

/********************   ETupTwo    ********************/

Exp make_ETupTwo(Exp p1, Exp p2, OptionExp p3)
{
    Exp tmp = (Exp) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating ETupTwo!\n");
        exit(1);
    }
    tmp->kind = is_ETupTwo;
    tmp->u.etuptwo_.exp_1 = p1;
    tmp->u.etuptwo_.exp_2 = p2;
    tmp->u.etuptwo_.optionexp_ = p3;
    return tmp;
}

/********************   EList    ********************/

Exp make_EList(ListExp p1)
{
    Exp tmp = (Exp) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating EList!\n");
        exit(1);
    }
    tmp->kind = is_EList;
    tmp->u.elist_.listexp_ = p1;
    return tmp;
}

/********************   TPNil    ********************/

TArgsPass make_TPNil()
{
    TArgsPass tmp = (TArgsPass) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating TPNil!\n");
        exit(1);
    }
    tmp->kind = is_TPNil;
    return tmp;
}

/********************   TPass    ********************/

TArgsPass make_TPass(ListType p1)
{
    TArgsPass tmp = (TArgsPass) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating TPass!\n");
        exit(1);
    }
    tmp->kind = is_TPass;
    tmp->u.tpass_.listtype_ = p1;
    return tmp;
}

/********************   ListExp    ********************/

ListExp make_ListExp(Exp p1, ListExp p2)
{
    ListExp tmp = (ListExp) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating ListExp!\n");
        exit(1);
    }
    tmp->exp_ = p1;
    tmp->listexp_ = p2;
    return tmp;
}

/********************   ONil    ********************/

OptionExp make_ONil()
{
    OptionExp tmp = (OptionExp) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating ONil!\n");
        exit(1);
    }
    tmp->kind = is_ONil;
    return tmp;
}

/********************   OExp    ********************/

OptionExp make_OExp(ListExp p1)
{
    OptionExp tmp = (OptionExp) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating OExp!\n");
        exit(1);
    }
    tmp->kind = is_OExp;
    tmp->u.oexp_.listexp_ = p1;
    return tmp;
}

/********************   LExp    ********************/

LamBody make_LExp(Exp p1)
{
    LamBody tmp = (LamBody) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating LExp!\n");
        exit(1);
    }
    tmp->kind = is_LExp;
    tmp->u.lexp_.exp_ = p1;
    return tmp;
}

/********************   LStm    ********************/

LamBody make_LStm(StmtBlock p1)
{
    LamBody tmp = (LamBody) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating LStm!\n");
        exit(1);
    }
    tmp->kind = is_LStm;
    tmp->u.lstm_.stmtblock_ = p1;
    return tmp;
}
