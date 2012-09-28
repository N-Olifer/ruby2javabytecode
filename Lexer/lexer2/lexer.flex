%{ 
	#include <stdio.h> 
	#include <locale.h>
	#include <string.h>
%} 

%option noyywrap 
%option never-interactive

IDENTIFIER [A-Za-z_][A-Za-z_0-9]*

%x STRING
%x STRING2
%x LINE_COMMENT
%x MULTILINE_COMMENT

%%

%{ 
	char comment[1000];
	char literal[1000];
%} 

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
<MULTILINE_COMMENT>\n
<MULTILINE_COMMENT>.* strcat(comment, yytext);


class printf("class : keyword\n");
super printf("super : keyword\n");
self printf("self : keyword\n");
sub printf("sub : keyword\n");
def printf("def : keyword\n");
return printf("return : keyword\n");
end printf("end : keyword\n");

if printf("if : keyword\n");
else printf("else : keyword\n");
elsif printf("elsif : keyword\n");
then printf("then : keyword\n");
for printf("for : keyword\n");
while printf("while : keyword\n");
until printf("until : keyword\n");
do printf("do : keyword\n");

public printf("public : keyword\n");
protected printf("protected : keyword\n");
private printf("private : keyword\n");

false printf("false : keyword\n");
true printf("true : keyword\n");
nil printf("nil : keyword\n");

";" printf(";\n");
"." printf(".\n");
"," printf(",\n");
"{" printf("{\n");
"}" printf("}\n");
"[" printf("[\n");
"]" printf("]\n");
"(" printf("(\n");
")" printf(")\n");
"+" printf("+ : operator\n");
"-" printf("- : operator\n");
"*" printf("* : operator\n");
"/" printf("/ : operator\n");
"=" printf("= : operator\n");
"==" printf("== : operator\n");
"<" printf("< : operator\n");
">" printf("> : operator\n");
">=" printf(">= : operator\n");
"<=" printf("<= : operator\n");
"!=" printf("!= : operator\n");
"||" printf("||\n");
"&&" printf("&&\n");
"!" printf("!\n");

0b[01]([01_]*[01])? printf("%s : bin constant\n", yytext);
0x[0-9A-Fa-f]([0-9A-Fa-f_]*[0-9A-Fa-f])? printf("%s : hex constant\n", yytext);
0[0-7]([0-7_]*[0-7])? printf("%s : oct constant\n", yytext);
[0-9]([0-9_]*[0-9])? printf("%s : dec constant\n", yytext);

{IDENTIFIER} printf("%s : identifier\n", yytext);
"$"{IDENTIFIER} printf("%s : $identifier\n", yytext);
"@"{IDENTIFIER} printf("%s : @identifier\n", yytext);
"@@"{IDENTIFIER} printf("%s : @@identifier\n", yytext);
{IDENTIFIER}"?" printf("%s : identifier?\n", yytext);
{IDENTIFIER}"!" printf("%s : identifier!\n", yytext);
{IDENTIFIER}"=" printf("%s : identifier=\n", yytext);

[[:blank:]]+ printf("space\n");
[\n]+ printf("next line\n");


\" { strcpy(literal,"");
    BEGIN(STRING);
    }
<STRING>[^\\\n\"]+ strcat(literal,yytext);
<STRING>\\n strcat(literal,"\n");
<STRING>\\\\ strcat(literal,"\\");
<STRING>\\\" strcat(literal,"\"");
<STRING>\\\' strcat(literal,"\'");
<STRING>\\r strcat(literal,"\r");
<STRING>\\s strcat(literal," ");
<STRING>\\t strcat(literal,"\t");
<STRING>\\;
<STRING>\" { 
    printf("String in \"\": %s\n", literal);
    BEGIN(INITIAL);
    }

\' { strcpy(literal,"");
    BEGIN(STRING2);
    }
<STRING2>[^\\\n\']+ strcat(literal,yytext);
<STRING2>\\n strcat(literal,"\n");
<STRING2>\\\' strcat(literal,"\'");
<STRING2>\' {
    printf("String in \'\': %s\n", literal);
    BEGIN(INITIAL);
    }
. printf("Error, unexpected lexem %s !!!!!!\n", yytext);

%%

void main(int argc, char* argv[])
{
    //setlocale(LC_CTYPE, ".1251");
    if (argc < 2)
    {
        yyin = fopen("test", "r");
    }
    else if((yyin = fopen(argv[1], "r")) == 0)
    {
        printf("Can't read file %s\n", argv[1]);
        exit(1);
    }
    yylex();
    system("pause");
}

