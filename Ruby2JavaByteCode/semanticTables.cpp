
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
        case CONSTANT_Class: return QString::number(numberRef1);
        case CONSTANT_Fieldref: return QString::number(numberRef1) + ", " + QString::number(numberRef2);
        case CONSTANT_Integer: return QString::number(intValue);
        case CONSTANT_Methodref: return QString::number(numberRef1) + ", " + QString::number(numberRef2);
        case CONSTANT_NameAndType: return QString::number(numberRef1) + ", " + QString::number(numberRef2);
        case CONSTANT_String: return QString::number(numberRef1);
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
    SemanticConst* newConst = new SemanticConst(CONSTANT_Utf8, constants.size(), value);
    constants.insert(newConst->number, newConst);
    return newConst->number;
}


int SemanticClass::addConstantInteger(int value)
{
    SemanticConst* newConst = new SemanticConst(CONSTANT_Integer, constants.size(), QString(), value);
    constants.insert(newConst->number, newConst);
    return newConst->number;
}


int SemanticClass::addConstantString(QString &value)
{
    SemanticConst* newConst = new SemanticConst(CONSTANT_String, constants.size(), QString(), 666, addConstantUtf8(value));
    constants.insert(newConst->number, newConst);
    return newConst->number;
}


int SemanticClass::addConstantNameAndType(QString &name, QString &type)
{
    SemanticConst* newConst = new SemanticConst(CONSTANT_NameAndType, constants.size(), QString(), 666, addConstantUtf8(name), addConstantUtf8(type));
    constants.insert(newConst->number, newConst);
    return newConst->number;
}


int SemanticClass::addConstantClass(QString &name)
{
    SemanticConst* newConst = new SemanticConst(CONSTANT_Class, constants.size(), QString(), 666, addConstantUtf8(name));
    constants.insert(newConst->number, newConst);
    return newConst->number;
}


int SemanticClass::addConstantFieldRef(QString &className, QString &fieldName, QString &type)
{
    SemanticConst* newConst = new SemanticConst(CONSTANT_Fieldref, constants.size(), QString(), 666, addConstantClass(className), addConstantNameAndType(fieldName, type));
    constants.insert(newConst->number, newConst);
    return newConst->number;
}


int SemanticClass::addConstantMethodRef(QString &className, QString &methodName, QString &type)
{
    SemanticConst* newConst = new SemanticConst(CONSTANT_Methodref, constants.size(), QString(), 666, addConstantClass(className), addConstantNameAndType(methodName, type));
    constants.insert(newConst->number, newConst);
    return newConst->number;
}


void SemanticMethod::addLocalVar(QString &name, SemanticClass *currentClass)
{
    if(!locals.contains(name))
    {
        SemanticVar* newVar = new SemanticVar();
        newVar->number = locals.count();
        locals.insert(name, newVar);
    }
}




