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
%s EXP_IN_STRING
%x LINE_COMMENT
%x MULTILINE_COMMENT

%%

%{ 
	char comment[1000];
	char literal[1000];
	char temp[1000];
%} 

\# {
	comment[0] = 0; 
	BEGIN(LINE_COMMENT);
}
<LINE_COMMENT>.* {
	strcat(comment, yytext); 
	printf("%s\t\tline comment\n",comment);
	BEGIN(INITIAL);
}

"=begin" {
	BEGIN(MULTILINE_COMMENT);
	comment[0] = 0;
}
<MULTILINE_COMMENT>"=end" {
	BEGIN(INITIAL);
	printf("%s\t\tmultiline comment\n", comment);
}
<MULTILINE_COMMENT>\n
<MULTILINE_COMMENT>.* strcat(comment, yytext);


class printf("class\t\tkeyword\n");
super printf("super\t\tkeyword\n");
self printf("self\t\tkeyword\n");
sub printf("sub\t\tkeyword\n");
def printf("def\t\tkeyword\n");
return printf("return\t\tkeyword\n");
end printf("end\t\tkeyword\n");

if printf("if\t\tkeyword\n");
else printf("else\t\tkeyword\n");
elsif printf("elsif\t\tkeyword\n");
then printf("then\t\tkeyword\n");
for printf("for\t\tkeyword\n");
while printf("while\t\tkeyword\n");
until printf("until\t\tkeyword\n");
do printf("do\t\tkeyword\n");
unless printf("unless\t\tkeyword\n");

public printf("public\t\tkeyword\n");
protected printf("protected\t\tkeyword\n");
private printf("private\t\tkeyword\n");

false printf("false\t\tkeyword\n");
true printf("true\t\tkeyword\n");
nil printf("nil\t\tkeyword\n");

\" { literal[0] = 0;
    BEGIN(STRING);
    }
<STRING>[^\\\n\"#{}]+ strcat(literal,yytext);
<STRING>\\n strcat(literal,"\n");
<STRING>\\\\ strcat(literal,"\\");
<STRING>\\\" strcat(literal,"\"");
<STRING>\\\' strcat(literal,"\'");
<STRING>\\r strcat(literal,"\r");
<STRING>\\s strcat(literal," ");
<STRING>\\t strcat(literal,"\t");
<STRING>\\[0-9]+ {
	int result;
	sscanf(yytext+1,"%o",&result);
	sprintf(literal + strlen(literal),"%c",result);
    }
<STRING>\\;
<STRING>"#" {
    printf("String in\"\"\t\t%s\n", literal);
	literal[0] = 0;
    printf("+\n");
    BEGIN(EXP_IN_STRING);
	}
<EXP_IN_STRING>\${IDENTIFIER} {
    printf("%s\t\t$identifier\n", yytext);
    printf(".to_s\t\tmethod to string\n");
    printf("+\n");
	BEGIN(STRING);
	}
<EXP_IN_STRING>\${IDENTIFIER}\" {
    printf("%s\t\t$identifier\n", yytext);
    printf(".to_s\t\tmethod to string\n");
    BEGIN(INITIAL);
	}
<EXP_IN_STRING>"{" {
    printf("String in\"\"\t\t%s\n", literal);
	literal[0] = 0;
    printf("+\n");
	printf("(\n");
    BEGIN(EXP_IN_STRING);
	}
<EXP_IN_STRING>"}" {
    printf(").to_s\t\tmethod to string\n");
    printf("+\n");
    BEGIN(STRING);
    }
<EXP_IN_STRING>"}\"" {
    printf(").to_s\t\tmethod to string\n");
    BEGIN(INITIAL); 
    }
<STRING>\" { 
    printf("String in \"\"\t\t%s\n", literal);
    BEGIN(INITIAL);
    }
\' { literal[0] = 0;
    BEGIN(STRING2);
    }
<STRING2>[^\\\n\']+ strcat(literal,yytext);
<STRING2>\\n strcat(literal,"\n");
<STRING2>\\\' strcat(literal,"\'");
<STRING2>\' {
    printf("String in \'\'\t\t%s\n", literal);
    BEGIN(INITIAL);
    }

";" printf(";\n");
"." printf(".\n");
"," printf(",\n");
"{" printf("{\n");
"}" printf("}\n");
"[" printf("[\n");
"]" printf("]\n");
"(" printf("(\n");
")" printf(")\n");
"+" printf("+\t\toperator\n");
"-" printf("-\t\toperator\n");
"*" printf("*\t\toperator\n");
"/" printf("/\t\toperator\n");
"=" printf("=\t\toperator\n");
"==" printf("==\t\toperator\n");
"<" printf("<\t\toperator\n");
">" printf(">\t\toperator\n");
">=" printf(">=\t\toperator\n");
"<=" printf("<=\t\toperator\n");
"!=" printf("!=\t\toperator\n");
"||" printf("||\n");
"&&" printf("&&\n");
"!" printf("!\n");

0b[01]([01_]*[01])? {
    int i, len = 0;
	long result;
	char *stop;
    for(i = 2; i < strlen(yytext); i++)
	    if(yytext[i] != '_')
            temp[len++] = yytext[i];
    temp[len] = '\0';
	result = strtol(temp, &stop, 2);
    printf("%s => %ld\t\tbin constant\n", temp, result);
    }
0x[0-9A-Fa-f]([0-9A-Fa-f_]*[0-9A-Fa-f])? {
    int i, len = 0;
	int result;
    for(i = 0; i < strlen(yytext); i++)
	    if(yytext[i] != '_')
            temp[len++] = yytext[i];
    temp[len] = '\0';
	_strupr(temp);
	sscanf(temp, "%X", &result);
    printf("%s => %d\t\thex constant\n", temp, result);
    }
0[0-7]([0-7_]*[0-7])? {
    int i, len = 0;
	int result;
    for(i = 0; i < strlen(yytext); i++)
	    if(yytext[i] != '_')
            temp[len++] = yytext[i];
    temp[len] = '\0';
	sscanf(temp, "%o", &result);
    printf("%s => %d\t\toct constant\n", temp, result);
    }
[0-9]([0-9_]*[0-9])? {
    int i, len = 0;
	int result;
    for(i = 0; i < strlen(yytext); i++)
	    if(yytext[i] != '_')
            temp[len++] = yytext[i];
    temp[len] = '\0';
	sscanf(temp, "%d", &result);
    printf("%s => %d\t\tdec constant\n", temp, result);
    }
{IDENTIFIER} printf("%s\t\tidentifier\n", yytext);
"$"{IDENTIFIER} printf("%s\t\t$identifier\n", yytext);
"@"{IDENTIFIER} printf("%s\t\t@identifier\n", yytext);
"@@"{IDENTIFIER} printf("%st\t\t@@identifier\n", yytext);
{IDENTIFIER}"?" printf("%s\t\tidentifier?\n", yytext);
{IDENTIFIER}"!" printf("%s\t\tidentifier!\n", yytext);
{IDENTIFIER}"=" printf("%s\t\tidentifier=\n", yytext);

[[:blank:]]+ printf("space\n");
[\n]+ printf("next line\n");

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
}

