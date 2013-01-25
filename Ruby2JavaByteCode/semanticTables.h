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
#define NAME_PRINT_METHOD "print"
#define NAME_PRINTLN_METHOD "println"
#define NAME_JAVA_OBJECT "java/lang/Object"

#define NAME_JAVA_STRING "java/lang/String"
#define DESC_JAVA_STRING_INIT "(L"NAME_JAVA_STRING";)V"
#define DESC_JAVA_STRING "L"NAME_JAVA_STRING";"

#define NAME_JAVA_INTEGER "java/lang/Integer"
#define DESC_JAVA_INTEGER "L"NAME_JAVA_INTEGER";"

#define NAME_RTL_INIT "<init>"
#define DESC_RTL_INIT_INT "(I)V"
#define DESC_RTL_INIT_UNINIT "()V"
#define DESC_RTL_INIT_OBJECT "("DESC_COMMON_CLASS")V"
#define DESC_RTL_INIT_ARRAY "("DESC_RTL_ARRAY")V"
#define DESC_RTL_INIT_STRING "("DESC_JAVA_STRING")V"

#define NAME_RTL_ADD "add"
#define DESC_RTL_ADD "("DESC_COMMON_VALUE")"DESC_COMMON_VALUE

#define NAME_RTL_ASSIGN "assign"
#define DESC_RTL_ASSIGN "(L"NAME_COMMON_VALUE";)"DESC_COMMON_VALUE

#define NAME_RTL_GET_OBJECT "getObject"
#define DESC_RTL_GET_OBJECT "()"DESC_COMMON_CLASS

#define NAME_RTL_GET_ARRAY "getArray"
#define DESC_RTL_GET_ARRAY "()"DESC_RTL_ARRAY

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

#define NAME_RTL_OR "or"
#define DESC_RTL_OR "("DESC_COMMON_VALUE")"DESC_COMMON_VALUE

#define NAME_RTL_AND "and"
#define DESC_RTL_AND "("DESC_COMMON_VALUE")"DESC_COMMON_VALUE

#define NAME_RTL_NOT "not"
#define DESC_RTL_NOT "()"DESC_COMMON_VALUE

#define NAME_RTL_UMINUS "uMinus"
#define DESC_RTL_UMINUS "()"DESC_COMMON_VALUE

#define NAME_RTL_GET_INT "getInt"
#define DESC_RTL_GET_INT "()I"

#define NAME_EXEPTION "java/lang/Exception"
#define DESC_EXEPTION "L"NAME_EXEPTION";"
#define DESC_EXEPTION_CONSTRUCTOR "(Ljava/lang/String;)V"

#define NAME_RTL_CONSOLE NAMESPACE "Console"
#define NAME_RTL_CONSOLE_PRINT_INT "printInt"
#define DESC_RTL_CONSOLE_PRINT_INT "("DESC_COMMON_VALUE")"DESC_COMMON_VALUE
#define NAME_RTL_CONSOLE_PRINTLN "println"
#define DESC_RTL_CONSOLE_PRINTLN "("DESC_COMMON_VALUE")"DESC_COMMON_VALUE
#define NAME_RTL_CONSOLE_PRINT "print"
#define DESC_RTL_CONSOLE_PRINT "("DESC_COMMON_VALUE")"DESC_COMMON_VALUE

#define NAME_RTL_ARRAY NAMESPACE "Array"
#define DESC_RTL_ARRAY "L"NAME_RTL_ARRAY";"

#define NAME_RTL_ARRAY_INIT "()V"
#define DESC_RTL_ARRAY_INIT "()V"
#define NAME_RTL_ARRAY_APPEND "append"
#define DESC_RTL_ARRAY_APPEND "("DESC_COMMON_VALUE")V"
#define NAME_RTL_ARRAY_GET "get"
#define DESC_RTL_ARRAY_GET "("DESC_COMMON_VALUE")"DESC_COMMON_VALUE
#define NAME_RTL_ARRAY_SET "set"
#define DESC_RTL_ARRAY_SET "("DESC_COMMON_VALUE""DESC_COMMON_VALUE")"DESC_COMMON_VALUE

#define ACC_CLASS_PUBLIC 0x0001
#define ACC_CLASS_ABSTRACT 0x0400
#define ACC_CLASS_SUPER 0x0020

#define ACC_FIELD_PUBLIC 0x0001
#define ACC_FIELD_STATIC 0x0008

#define ATTR_CODE "Code"

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
    int constClass; // Номер константы собственного класса
    int constParent; // Номер константы класса-родителя

    int constCommonValueClass;

    // Константы для обращений к RTL
    int constRTLAddRef;
    int constRTLInitIntRef;
	int constRTLInitStringRef;
    int constRTLAssignRef;
    int constRTLInitUninitRef;
	int constRTLConsolePrintIntRef;
	int constRTLConsolePrintRef;
	int constRTLConsolePrintlnRef;
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

    int constRTLOrRef;
    int constRTLAndRef;
    int constRTLNotRef;

    int constRTLUMinusRef;

    int constExeptionClassRef;
    int constExeptionInitRef;
    int constStringClassRef;
    int constStringInitRef;

    int constIncorrectMethodExepText;

	int constRTLInitByArrayRef;
	int constRTLGetArrayRef;
	int constRTLClassArray;
	int constRTLInitArrayRef;
	int constRTLArrayAppendRef;
	int constRTLArrayGetRef;
	int constRTLArraySetRef;

    bool isAbstract;

    QString id; // Имя класса
    QString parentId; // Имя родителя

    QMap<QString, SemanticMethod*> methods; // Методы
    QMap<int, SemanticConst*> constants; // Таблица констант
    QMap<QString, SemanticVar*> fields; // Поля

    AttrClassDef* classDef; // Указатель на узел дерева

    SemanticClass() { isAbstract = false; }

    // Добавление поля
    void addField(QString & id, bool isStatic);

    // Добавление констант
    int addConstantUtf8(QString & value);
    int addConstantInteger(int value);
    int addConstantString(QString & value);
    int addConstantNameAndType(QString & name, QString & type);
    int addConstantClass(QString & name);
    int addConstantFieldRef(QString & className, QString & fieldName, QString & type);
    int addConstantMethodRef(QString & className, QString & methodName, QString & type);

    void addRTLConstants();

    // Генерация class-файла
    void generate();
};

class SemanticConst
{
public:
    SemanticConst(ConstType type, int number, QString & strValue = QString(), int intValue = EMPTY_CONST_NUMBER, int ref1 = EMPTY_CONST_NUMBER, int ref2 = EMPTY_CONST_NUMBER);

    ConstType type;
    int number; // Номер константы

    QString strValue; // Строковое значение
    int intValue; // Числовое значение

    int numberRef1; // Номер первой константы, на которую ссылается
    int numberRef2; // Номер второй константы, на которую ссылается

    // Строковое представление типа константы
    QString typeToString();

    // Строковое представление значения
    QString valueToString();

    // Строковое представление номера
    QString numberToString();
};

QDataStream & operator<< (QDataStream& out, const SemanticConst *constant);

class SemanticMethod
{
public:
    QString id;
    int constName; // номер константы имени
    int constDesc; // номер константы дескриптора
    int constCode; // номер константы Code

    bool abstract;
    QMap<QString, SemanticVar*> locals; // Таблица локальных переменных
    int paramCount; // Количество параметров
    AttrMethodDef* methodDef; // Указатель на узел в дереве

    // Добавление локальной переменной
    void addLocalVar(QString & name, SemanticClass* currentClass);

    // Генерация кода
    void generate(QDataStream & out, SemanticClass* curClass);

    // Является ли имя метода специальным (new, super и т. д.)
    static bool isSpecialMethodName(const QString & name);
};

class SemanticVar
{
public:
    int constName; // номер константы имени
    int constType; // номер константы типа
    int number; // Номер в талице
    bool isStatic; // Является ли статическим полем

    SemanticVar(bool isStatic) { this->isStatic = isStatic; };
};

QDataStream & operator<< (QDataStream& out, const SemanticVar *var);

#endif // TABLES_H
