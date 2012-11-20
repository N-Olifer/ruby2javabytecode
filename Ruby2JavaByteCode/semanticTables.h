#ifndef TABLES_H
#define TABLES_H
#include <qmap.h>
#include <qhash.h>


class TableClass;
class TableConst;
class TableMethod;
class TableVar;


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


class TableClass
{
public:
    QHash<QString, TableMethod> methods;
    QHash<int, TableConst> constants;
    QHash<QString, TableVar> fields;
};

class TableConst
{
public:
    ConstType type;
    int number;

    QString value;

    int numberRef1;
    int numberRef2;
};

class TableMethod
{
public:
    QHash<QString, TableVar> locals;
};

class TableVar
{
public:
    int number;
};

#endif // TABLES_H
