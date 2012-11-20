#include <QCoreApplication>
#include "parser_tab.h"
#include "test.h"
#include "structures.h"
#include "Semantic.h"

extern int yyparse(void);
extern FILE * yyin;
extern struct ProgramNode * root;

//void semantic()
//{
//    AttrProgramNode* attrNode = new AttrProgramNode();

//}

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

    return 0;
}
