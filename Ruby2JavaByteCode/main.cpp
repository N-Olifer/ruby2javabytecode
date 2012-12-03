#include <QCoreApplication>
#include "parser_tab.h"
#include "test.h"
#include "structures.h"
#include "Semantic.h"
#include <qfile.h>
#include <qtextstream.h>
#include <qprocess.h>
#include <qtablewidget>
#include <QApplication>

extern int yyparse(void);
extern FILE * yyin;
extern struct ProgramNode * root;

void generateCode(SemanticAnalyzer* sem)
{
    QFile file("result.txt");
    if(file.open(QIODevice::WriteOnly))
    {
        QDataStream out(&file);

        //sem->generate(out);

        file.close();
    }
}

void showConstantsTable(SemanticAnalyzer* sem)
{
    foreach(SemanticClass* semClass, sem->classTable)
    {
        QTableWidget* table = new QTableWidget();
        table->setRowCount(semClass->constants.count() + semClass->methods.count() + semClass->fields.count() + 2);
        table->setColumnCount(3);
        table->show();
        table->setWindowTitle(semClass->id);
        int row = 0;
        foreach(SemanticConst* constant, semClass->constants)
        {
            table->setItem(row, 0, new QTableWidgetItem(constant->numberToString()));
            table->setItem(row, 1, new QTableWidgetItem(constant->typeToString()));
            table->setItem(row, 2, new QTableWidgetItem(constant->valueToString()));
            row++;
        }
        row++;
        foreach(SemanticMethod* meth, semClass->methods)
        {
            table->setItem(row, 0, new QTableWidgetItem(meth->id));
            table->setItem(row, 1, new QTableWidgetItem(QString::number(meth->constName)));
            table->setItem(row, 2, new QTableWidgetItem(QString::number(meth->constDesc)));
            row++;
        }
        row++;
        foreach(SemanticVar* var, semClass->fields)
        {
            table->setItem(row, 0, new QTableWidgetItem(QString::number(var->number)));
            table->setItem(row, 1, new QTableWidgetItem(semClass->fields.key(var)));
            row++;
        }
    }
}

void semantic()
{
    SemanticAnalyzer* sem = new SemanticAnalyzer(root);

    QFile file("dot2.txt");
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream out(&file);

        sem->dotPrint(out);

        file.close();
        QProcess::execute("dot.exe -Tpng -oresult2.png dot2.txt");
    }
    sem->doSemantics();

    QTextStream out(stdout);
    foreach(QString error, sem->errors)
        out << error << "\n";

    showConstantsTable(sem);
    generateCode(sem);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(argc < 2)
    {
        yyin = fopen("test1.txt", "r");
    }
    else if((yyin = fopen(argv[1], "r")) == 0)
    {
        printf("Can't read file %s\n", argv[1]);
        exit(1);
    }

    int result = yyparse();
    //printTree(root);

    if(!result)
        semantic();


    return a.exec();
}
