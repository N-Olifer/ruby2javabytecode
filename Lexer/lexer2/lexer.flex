%{ 
	#include <stdio.h> 
	#include <locale.h>
	#include <string.h>
	
	char comment[666];
	char literal[1000];
%} 

%option noyywrap 
%option never-interactive

IDENTIFIER [A-Za-z_][A-Za-z_0-9]*

%x STRING
%x LINE_COMMENT
%x MULTILINE_COMMENT

%%

\# {
	comment[0] = 0; 
	BEGIN(LINE_COMMENT);
}
<LINE_COMMENT>.* {
	strcat(comment, yytext); 
	printf("%s : line comment\n",comment);
	BEGIN(INITIAL);
}

"=begin" {
	BEGIN(MULTILINE_COMMENT);
	comment[0] = 0;
}

<MULTILINE_COMMENT>"=end" {
	BEGIN(INITIAL);
	printf("%s : multiline comment\n", comment);
}

<MULTILINE_COMMENT>. strcat(comment, yytext);
<MULTILINE_COMMENT>\n

class printf("class\n");
super printf("super\n");
self printf("self\n");
sub printf("sub\n");
def printf("def\n");
return printf("return\n");
end printf("end\n");

\* printf("*\n");
\; printf(";\n");
\. printf(".\n");
\, printf(",\n");
\{ printf("{\n");
\} printf("}\n");
\[ printf("[\n");
\] printf("]\n");
\( printf("(\n");
\) printf(")\n");
\+ printf("+\n");
\- printf("-\n");
\/ printf("/\n");
\= printf("=\n");
\=\= printf("==\n");
\< printf("<\n");
\> printf(">\n");
\>\= printf(">=\n");
\<\= printf("<=\n");
\!\= printf("!=\n");

false printf("false\n");
true printf("true\n");
nil printf("nil\n");

\|\| printf("||\n");
\&\& printf("&&\n");
\! printf("!\n");

if printf("if\n");
else printf("else\n");
elsif printf("elsif\n");
then printf("then\n");
for printf("for\n");
while printf("while\n");
until printf("until\n");
do printf("do\n");

[0-9]+ printf("%s : dec constant\n", yytext);

{IDENTIFIER} printf("%s : identifier\n", yytext);
\${IDENTIFIER} printf("%s : $identifier\n", yytext);
\@{IDENTIFIER} printf("%s : @identifier\n", yytext);
\@\@{IDENTIFIER} printf("%s : @@identifier\n", yytext);
{IDENTIFIER}\? printf("%s : identifier?\n", yytext);
{IDENTIFIER}\! printf("%s : identifier!\n", yytext);
{IDENTIFIER}\= printf("%s : identifier=\n", yytext);


[[:blank:]]+
[\n\t]+



\" {
    strcpy(literal,"");
    BEGIN(STRING);
    }
<STRING>[^\\\n\"]+ strcat(literal,yytext);
<STRING>\\n strcat(literal,"\n");
<STRING>\\\\ strcat(literal,"\\");
<STRING>\\\" strcat(literal,"\"");
<STRING>\\r strcat(literal,"\r");
<STRING>\\s strcat(literal," ");
<STRING>\\t strcat(literal,"\t");
<STRING>\" { 
    printf("String in \"\": %s\n", literal);
    BEGIN(INITIAL);
    }


. printf("Error, unexpected lexem %s !!!!!!\n", yytext);
%%

void main(int argc, char* argv[])
{
    //setlocale(LC_CTYPE, ".1251");
    if (argc < 2)
    {
        yyin = fopen("test.txt", "r");
    }
    else if((yyin = fopen(argv[1], "r")) == 0)
    {
        printf("Невозможно открыть файл %s\n", argv[1]);
        exit(1);
    }
    yylex();
    system("pause");
}

