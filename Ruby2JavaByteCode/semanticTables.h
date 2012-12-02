#ifndef TABLES_H
#define TABLES_H

#include <qmap.h>
#include <qhash.h>

class SemanticClass;
class SemanticConst;
class SemanticMethod;
class SemanticVar;

#define EMPTY_CONST_NUMBER -1

#define NAME_COMMON_CLASS "<CommonClass>"
#define NAME_MAIN_CLASS "<MainClass>"
#define NAME_MAIN_CLASS_METHOD "main"
#define NAME_DEFAULT_CONSTRUCTOR "<init>"
#define NAME_JAVA_OBJECT "Object"
#define VALUE_MAX2BIT 65535

#define DESC_COMMON_CLASS "L"NAME_COMMON_CLASS";"

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
    bool abstract;

    QString id;
    QString parentId;

    QHash<QString, SemanticMethod*> methods;
    QHash<int, SemanticConst*> constants;
    QHash<QString, SemanticVar*> fields;
    QHash<QString, SemanticClass*> classes;

    void addField(QString & id);

    int addConstantUtf8(QString & value);
    int addConstantInteger(int value);
    int addConstantString(QString & value);
    int addConstantNameAndType(QString & name, QString & type);
    int addConstantClass(QString & name);
    int addConstantFieldRef(QString & className, QString & fieldName, QString & type);
    int addConstantMethodRef(QString & className, QString & methodName, QString & type);
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

class SemanticMethod
{
public:
    QString id;
    int constMethodRef;
    bool abstract;
    QHash<QString, SemanticVar*> locals;

    void addLocalVar(QString & name, SemanticClass* currentClass);

};

class SemanticVar
{
public:
    int number;
};

#endif // TABLES_H
