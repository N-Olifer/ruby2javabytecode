#ifndef TABLES_H
#define TABLES_H
#include <qmap.h>
#include <qhash.h>

class SemanticClass;
class SemanticConst;
class SemanticMethod;
class SemanticVar;


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
    QHash<QString, SemanticMethod> methods;
    QHash<int, SemanticConst> constants;
    QHash<QString, SemanticVar> fields;
};

class SemanticConst
{
public:
    ConstType type;
    int number;

    QString value;

    int numberRef1;
    int numberRef2;
};

class SemanticMethod
{
public:
    int consctName;
    int constDesc;
    bool abstract;
    QHash<QString, SemanticVar> locals;

};

class SemanticVar
{
public:
    int constName;
    int constDesc;
    int number;
};

#endif // TABLES_H
