
#include "SemanticTables.h"



SemanticConst::SemanticConst(ConstType type, int number, QString & value, int intValue, int ref1, int ref2)
{

    this->type = type;
    this->number = number;
    this->strValue = value;
    this->numberRef1 = ref1;
    this->numberRef2 = ref2;
}

QString SemanticConst::typeToString()
{
    switch(type)
    {
        case CONSTANT_Class: return "Class";
        case CONSTANT_Fieldref: return "FieldRef";
        case CONSTANT_Integer: return "Integer";
        case CONSTANT_Methodref: return "MethodRef";
        case CONSTANT_NameAndType: return "NameAndType";
        case CONSTANT_String: return "String";
        case CONSTANT_Utf8: return "Utf8";
    }
}

QString SemanticConst::valueToString()
{
    QString result;
    switch(type)
    {
        case CONSTANT_String:
        case CONSTANT_Class: return QString::number(numberRef1);
        case CONSTANT_Integer: return QString::number(intValue);
        case CONSTANT_Fieldref:
        case CONSTANT_Methodref:
        case CONSTANT_NameAndType: return QString::number(numberRef1) + ", " + QString::number(numberRef2);      
        case CONSTANT_Utf8: return strValue;
    }
}


QString SemanticConst::numberToString()
{
    return QString::number(number);
}

void SemanticClass::addField(QString &id)
{
    SemanticVar* newField = new SemanticVar();
    newField->number = fields.size();
    fields.insert(id, newField);
}

int SemanticClass::addConstantUtf8(QString &value)
{
    foreach(SemanticConst* constant, constants)
    {
        if(constant->type == CONSTANT_Utf8 && constant->strValue == value)
            return constant->number;
    }

    SemanticConst* newConst = new SemanticConst(CONSTANT_Utf8, constants.size() + 1, value);
    constants.insert(newConst->number, newConst);
    return newConst->number;
}


int SemanticClass::addConstantInteger(int value)
{
    foreach(SemanticConst* constant, constants)
    {
        if(constant->type == CONSTANT_Integer && constant->intValue == value)
            return constant->number;
    }

    SemanticConst* newConst = new SemanticConst(CONSTANT_Integer, constants.size() + 1, QString(), value);
    constants.insert(newConst->number, newConst);
    return newConst->number;
}


int SemanticClass::addConstantString(QString &value)
{
    int utf8Num = addConstantUtf8(value);

    foreach(SemanticConst* constant, constants)
    {
        if(constant->type == CONSTANT_String && constant->numberRef1 == utf8Num)
            return constant->number;
    }

    SemanticConst* newConst = new SemanticConst(CONSTANT_String, constants.size() + 1, QString(), EMPTY_CONST_NUMBER, utf8Num);
    constants.insert(newConst->number, newConst);
    return newConst->number;
}


int SemanticClass::addConstantNameAndType(QString &name, QString &type)
{
    int utf8Name = addConstantUtf8(name);
    int utf8Type = addConstantUtf8(type);

    foreach(SemanticConst* constant, constants)
    {
        if(constant->type == CONSTANT_NameAndType && constant->numberRef1 == utf8Name && constant->numberRef2 == utf8Type)
            return constant->number;
    }

    SemanticConst* newConst = new SemanticConst(CONSTANT_NameAndType, constants.size() + 1, QString(), EMPTY_CONST_NUMBER, utf8Name, utf8Type);
    constants.insert(newConst->number, newConst);
    return newConst->number;
}


int SemanticClass::addConstantClass(QString &name)
{
    int utf8Name = addConstantUtf8(name);

    foreach(SemanticConst* constant, constants)
    {
        if(constant->type == CONSTANT_Class && constant->numberRef1 == utf8Name)
            return constant->number;
    }
    SemanticConst* newConst = new SemanticConst(CONSTANT_Class, constants.size() + 1, QString(), EMPTY_CONST_NUMBER, utf8Name);
    constants.insert(newConst->number, newConst);
    return newConst->number;
}


int SemanticClass::addConstantFieldRef(QString &className, QString &fieldName, QString &type)
{
    int classNum = addConstantClass(className);
    int nameAndTypeNum = addConstantNameAndType(fieldName, type);

    foreach(SemanticConst* constant, constants)
    {
        if(constant->type == CONSTANT_Fieldref && constant->numberRef1 == classNum && constant->numberRef2 == nameAndTypeNum)
            return constant->number;
    }

    SemanticConst* newConst = new SemanticConst(CONSTANT_Fieldref, constants.size() + 1, QString(), EMPTY_CONST_NUMBER, classNum, nameAndTypeNum);
    constants.insert(newConst->number, newConst);
    return newConst->number;
}


int SemanticClass::addConstantMethodRef(QString &className, QString &methodName, QString &type)
{
    int classNum = addConstantClass(className);
    int nameAndTypeNum = addConstantNameAndType(methodName, type);

    foreach(SemanticConst* constant, constants)
    {
        if(constant->type == CONSTANT_Fieldref && constant->numberRef1 == classNum && constant->numberRef2 == nameAndTypeNum)
            return constant->number;
    }

    SemanticConst* newConst = new SemanticConst(CONSTANT_Methodref, constants.size() + 1, QString(), EMPTY_CONST_NUMBER, classNum, nameAndTypeNum);
    constants.insert(newConst->number, newConst);
    return newConst->number;
}


void SemanticMethod::addLocalVar(QString &name, SemanticClass *currentClass)
{
    if(!locals.contains(name))
    {
        SemanticVar* newVar = new SemanticVar();
        newVar->number = locals.count() + 1;
        locals.insert(name, newVar);
    }
}




