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
#define NAME_MAIN_CLASS "MainClasszz"
#define NAME_MAIN_CLASS_METHOD "main"
#define NAME_COMMON_VALUE NAMESPACE"CommonValue"
#define NAME_DEFAULT_CONSTRUCTOR "<init>"
#define NAME_SUPER_METHOD "super"
#define NAME_JAVA_OBJECT "java/lang/Object"
#define NAME_JAVA_STRING "java/lang/String"

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
    CONSTANT_Utf8 = 1,
    CONSTANT_Integer = 3,
    CONSTANT_String = 8,
    CONSTANT_NameAndType = 12,
    CONSTANT_Class = 7,
    CONSTANT_Fieldref = 9,
    CONSTANT_Methodref = 10
};

class SemanticClass
{
public:
    int constClass;
    int constParent;
    bool isAbstract;

    QString id;
    QString parentId;

    QHash<QString, SemanticMethod*> methods;
    QHash<int, SemanticConst*> constants;
    QHash<QString, SemanticVar*> fields;

    SemanticClass() { isAbstract = false; }
    AttrClassDef* classDef;

    void addField(QString & id);
   // void addMethod(QString & name, QString & desc);

    int addConstantUtf8(QString & value);
    int addConstantInteger(int value);
    int addConstantString(QString & value);
    int addConstantNameAndType(QString & name, QString & type);
    int addConstantClass(QString & name);
    int addConstantFieldRef(QString & className, QString & fieldName, QString & type);
    int addConstantMethodRef(QString & className, QString & methodName, QString & type);

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
    QHash<QString, SemanticVar*> locals;
    int paramCount;
    AttrMethodDef* methodDef;

    void addLocalVar(QString & name, SemanticClass* currentClass);

    void generate(QDataStream & out, SemanticClass* curClass);
};

class SemanticVar
{
public:
    int constName;
    int constType;
    int number;
};

QDataStream & operator<< (QDataStream& out, const SemanticVar *var);

#endif // TABLES_H
