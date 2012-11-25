#include <QCoreApplication>
#include "parser_tab.h"
#include "test.h"
#include "structures.h"
#include "Semantic.h"
#include <qfile.h>
#include <qtextstream.h>
#include <qprocess.h>

extern int yyparse(void);
extern FILE * yyin;
extern struct ProgramNode * root;

void semantic()
{
    Semantics* sem = new Semantics(root);

    QFile file("dot2.txt");
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream out(&file);

        sem->dotPrint(out);
        file.close();
        QProcess::execute("dot.exe -Tpng -oresult2.png dot2.txt");
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if(argc < 2)
    {
        yyin = fopen("test1.txt", "r");
    }
    else if((yyin = fopen(argv[1], "r")) == 0)
    {
        printf("Can't read file %s\n", argv[1]);
        exit(1);
    }

    yyparse();
    printTree(root);
    semantic();

    return 0;
}
