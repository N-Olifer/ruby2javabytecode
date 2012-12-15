
#include "SemanticTables.h"
#include "semantic.h"
#include <QFile>

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

QDataStream & operator<<(QDataStream& out, const SemanticConst *constant)
{
    out << (quint8)constant->type;
    int tt;
    switch(constant->type)
    {
        case CONSTANT_String:
        case CONSTANT_Class: out << (quint16)constant->numberRef1;
            break;
        case CONSTANT_Integer: out << (qint32)constant->intValue;
            break;
        case CONSTANT_Fieldref:
        case CONSTANT_Methodref:
        case CONSTANT_NameAndType: out << (quint16)constant->numberRef1 << (quint16)constant->numberRef2;
            break;
        case CONSTANT_Utf8: out << (quint16)constant->strValue.size();
            tt = out.writeRawData(constant->strValue.toLocal8Bit().data(), constant->strValue.size());
    }
    return out;
}

void SemanticClass::addField(QString &id)
{
    SemanticVar* newField = new SemanticVar();
    newField->number = fields.size();
    newField->constName = addConstantUtf8(id);
    newField->constType = addConstantUtf8(QString(DESC_COMMON_CLASS));
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

void SemanticClass::addRTLConstants()
{
    constCommonValueClass = addConstantClass(QString(NAME_COMMON_VALUE));
    constRTLInitIntRef = addConstantMethodRef(QString(NAME_COMMON_VALUE), QString(NAME_RTL_INIT), QString(DESC_RTL_INIT_INT));
    constRTLAddRef = addConstantMethodRef(QString(NAME_COMMON_VALUE), QString(NAME_RTL_ADD), QString(DESC_RTL_ADD));
    constRTLAssignRef = addConstantMethodRef(QString(NAME_COMMON_VALUE), QString(NAME_RTL_ASSIGN), QString(DESC_RTL_ASSIGN));
}

void SemanticClass::generate()
{
    QFile file(id + ".class");
    if(file.open(QIODevice::WriteOnly))
    {
        QDataStream out(&file);

        out << 0xCAFEBABE << 0x00000032;
        out << (quint16)(constants.count() + 1);

        foreach(SemanticConst* constant, constants)
            out << constant;

        out << (quint16)(ACC_CLASS_SUPER | ACC_CLASS_PUBLIC);
        out << (quint16)constClass;
        out << (quint16)constParent;
        out << (quint16)0;
        out << (quint16)fields.count();

        foreach(SemanticVar* field, fields)
            out << field;

        out << (quint16)methods.count();

        foreach(SemanticMethod* method, methods)
            method->generate(out, this);

        out << (quint16)0;
    }
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

void SemanticMethod::generate(QDataStream &out, SemanticClass* curClass)
{
    //if(id == NAME_DEFAULT_CONSTRUCTOR)
     //   return; //TODO

    quint16 flags;
    if(methodDef->isStatic)
    {
        flags = ACC_FIELD_PUBLIC | ACC_FIELD_STATIC;
    }
    else
        flags = ACC_FIELD_PUBLIC;

    out << (quint16)flags;
    out << (quint16)constName;
    out << (quint16)constDesc;
    out << (quint16)1; // ��������� ���������


    methodDef->generateCode(out, curClass);
}

QDataStream & operator<< (QDataStream& out, const SemanticVar *var)
{
    out << (quint16)ACC_FIELD_PUBLIC;
    out << (quint16)var->constName;
    out << (quint16)var->constType;
    out << (quint16)0;
    return out;
}


