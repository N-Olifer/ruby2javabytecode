#ifndef TABLES_H
#define TABLES_H

#include <qmap.h>
#include <qhash.h>
#include <QDataStream>

class SemanticClass;
class SemanticConst;
class SemanticMethod;
class SemanticVar;

class AttrClassDef;
class AttrMethodDef;

#define EMPTY_CONST_NUMBER -1
#define NAMESPACE "Ruby/"

#define NAME_COMMON_CLASS NAMESPACE"CommonClass"
#define NAME_MAIN_CLASS "MainClass"
#define NAME_MAIN_CLASS_METHOD "main"
#define NAME_COMMON_VALUE NAMESPACE"CommonValue"
#define NAME_DEFAULT_CONSTRUCTOR "<init>"
#define NAME_SUPER_METHOD "super"
#define NAME_SELF "self"
#define NAME_NIL "nil"
#define NAME_NEW_METHOD "new"
#define NAME_PRINTINT_METHOD "printInt"
#define NAME_JAVA_OBJECT "java/lang/Object"
#define NAME_JAVA_STRING "java/lang/String"

#define NAME_RTL_INIT "<init>"
#define DESC_RTL_INIT_INT "(I)V"
#define DESC_RTL_INIT_UNINIT "()V"
#define DESC_RTL_INIT_OBJECT "("DESC_COMMON_CLASS")V"

#define NAME_RTL_ADD "add"
#define DESC_RTL_ADD "("DESC_COMMON_VALUE")"DESC_COMMON_VALUE

#define NAME_RTL_ASSIGN "assign"
#define DESC_RTL_ASSIGN "(L"NAME_COMMON_VALUE";)"DESC_COMMON_VALUE

#define NAME_RTL_GET_OBJECT "getObject"
#define DESC_RTL_GET_OBJECT "()"DESC_COMMON_CLASS

#define NAME_RTL_MUL "mul"
#define DESC_RTL_MUL "("DESC_COMMON_VALUE")"DESC_COMMON_VALUE

#define NAME_RTL_DIV "div"
#define DESC_RTL_DIV "("DESC_COMMON_VALUE")"DESC_COMMON_VALUE

#define NAME_RTL_MINUS "minus"
#define DESC_RTL_MINUS "("DESC_COMMON_VALUE")"DESC_COMMON_VALUE

#define NAME_RTL_LESS "less"
#define DESC_RTL_LESS "("DESC_COMMON_VALUE")"DESC_COMMON_VALUE

#define NAME_RTL_MORE "more"
#define DESC_RTL_MORE "("DESC_COMMON_VALUE")"DESC_COMMON_VALUE

#define NAME_RTL_EQU "equ"
#define DESC_RTL_EQU "("DESC_COMMON_VALUE")"DESC_COMMON_VALUE

#define NAME_RTL_NEQU "nequ"
#define DESC_RTL_NEQU "("DESC_COMMON_VALUE")"DESC_COMMON_VALUE

#define NAME_RTL_UMINUS "uMinus"
#define DESC_RTL_UMINUS "()"DESC_COMMON_VALUE

#define NAME_RTL_GET_INT "getInt"
#define DESC_RTL_GET_INT "()I"

#define NAME_RTL_CONSOLE NAMESPACE "Console"
#define NAME_RTL_CONSOLE_PRINT_INT "printInt"
#define DESC_RTL_CONSOLE_PRINT_INT "("DESC_COMMON_VALUE")"DESC_COMMON_VALUE
#define NAME_RTL_CONSOLE_PRINT_STRING "printString"
#define DESC_RTL_CONSOLE_PRINT_STRING "("DESC_COMMON_VALUE")"DESC_COMMON_VALUE

#define ACC_CLASS_PUBLIC 0x0001
#define ACC_CLASS_ABSTRACT 0x0400
#define ACC_CLASS_SUPER 0x0020

#define ACC_FIELD_PUBLIC 0x0001
#define ACC_FIELD_STATIC 0x0008

#define ATTR_CODE "Code"

#define VALUE_MAX2BIT 65535

#define DESC_COMMON_CLASS "L"NAME_COMMON_CLASS";"
#define DESC_COMMON_VALUE "L"NAME_COMMON_VALUE";"
#define DESC_MAIN_CLASS_METHOD "([L"NAME_JAVA_STRING";)V"

enum ConstType
{
    CONSTANT_Utf8			= 1,
    CONSTANT_Integer		= 3,
    CONSTANT_String			= 8,
    CONSTANT_NameAndType	= 12,
    CONSTANT_Class			= 7,
    CONSTANT_Fieldref		= 9,
    CONSTANT_Methodref		= 10
};

class SemanticClass
{
public:
    int constClass;
    int constParent;

    int constCommonValueClass;

    int constRTLAddRef;
    int constRTLInitIntRef;
    int constRTLAssignRef;
    int constRTLInitUninitRef;
	int constRTLConsolePrintIntRef;
	int constRTLConsolePrintStringRef;
    int constRTLInitObjectRef;
    int constRTLGetObjectRef;
    int constRTLMulRef;
    int constRTLDivRef;
    int constRTLMinusRef;
    int constRTLGetIntRef;
    int constRTLLessRef;
    int constRTLMoreRef;
    int constRTLEquRef;
    int constRTLNequRef;
    int constRTLUMinusRef;
    bool isAbstract;

    QString id;
    QString parentId;

    QMap<QString, SemanticMethod*> methods;
    QMap<int, SemanticConst*> constants;
    QMap<QString, SemanticVar*> fields;

    AttrClassDef* classDef;

    SemanticClass() { isAbstract = false; }
    void addField(QString & id, bool isStatic);

    int addConstantUtf8(QString & value);
    int addConstantInteger(int value);
    int addConstantString(QString & value);
    int addConstantNameAndType(QString & name, QString & type);
    int addConstantClass(QString & name);
    int addConstantFieldRef(QString & className, QString & fieldName, QString & type);
    int addConstantMethodRef(QString & className, QString & methodName, QString & type);

    void addRTLConstants();

    void generate();
};

class SemanticConst
{
public:
    SemanticConst(ConstType type, int number, QString & strValue = QString(), int intValue = 666, int ref1 = -1, int ref2 = -1);

    ConstType type;
    int number; // Номер константы

    QString strValue;
    int intValue;

    int numberRef1;
    int numberRef2;

    QString typeToString();
    QString valueToString();
    QString numberToString();
};

QDataStream & operator<< (QDataStream& out, const SemanticConst *constant);

class SemanticMethod
{
public:
    QString id;
    int constName;
    int constDesc;
    int constCode;
    bool abstract;
    QMap<QString, SemanticVar*> locals;
    int paramCount;
    AttrMethodDef* methodDef;

    void addLocalVar(QString & name, SemanticClass* currentClass);

    void generate(QDataStream & out, SemanticClass* curClass);

    static bool isSpecialMethodName(const QString & name);
};

class SemanticVar
{
public:
    int constName;
    int constType;
    int number;
    bool isStatic;

    SemanticVar(bool isStatic) { this->isStatic = isStatic; };
};

QDataStream & operator<< (QDataStream& out, const SemanticVar *var);

#endif // TABLES_H
