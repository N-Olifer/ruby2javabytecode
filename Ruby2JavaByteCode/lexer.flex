%{ 
	#include <stdio.h> 
	#include <locale.h>
	#include <string.h>
    #include "parser_tab.h"
	#include "structures.h"
	#include "test.h"
%} 

%option noyywrap 
%option never-interactive
%option outfile="lex.yy.cpp"

IDENTIFIER [A-Za-z_][A-Za-z_0-9]*
SPACE_OR_EOL ([\n]+)|([\n]+([[:blank:]]+|[\n]+)+)|([[:blank:]]+)

%x STRING_X
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
	//printf("%s\t\tline comment\n",comment);
	BEGIN(INITIAL);
}

"=begin" {
	BEGIN(MULTILINE_COMMENT);
	comment[0] = 0;
}
<MULTILINE_COMMENT>"=end" {
	BEGIN(INITIAL);
	//printf("%s\t\tmultiline comment\n", comment);
}
<MULTILINE_COMMENT>\n
<MULTILINE_COMMENT>.* strcat(comment, yytext);


class return CLASS;
super return SUPER;
def return DEF;
def{SPACE_OR_EOL}+self{SPACE_OR_EOL}*"." return DEF_STATIC;
return return RETURN;
end return END;

if return IF;
else return ELSE;
elsif return ELSIF;
then return THEN;
while return WHILE;
until return UNTIL;
do return DO;
unless return UNLESS;

false return FALSE;
true return TRUE;

\" { literal[0] = 0;
    BEGIN(STRING_X);
    }
<STRING_X>[^\\\n\"#{}]+ strcat(literal,yytext);
<STRING_X>\\n strcat(literal,"\n");
<STRING_X>\\\\ strcat(literal,"\\");
<STRING_X>\\\" strcat(literal,"\"");
<STRING_X>\\\' strcat(literal,"\'");
<STRING_X>\\r strcat(literal,"\r");
<STRING_X>\\s strcat(literal," ");
<STRING_X>\\t strcat(literal,"\t");
<STRING_X>\\[0-9]+ {
	int result;
	sscanf(yytext+1,"%o",&result);
	sprintf(literal + strlen(literal),"%c",result);
    }
<STRING_X>\\;
<STRING_X>"#{" {
    BEGIN(INITIAL);
	
	char * ttt = (char*)malloc(sizeof(char)*strlen(literal)+3);
	ttt[0]= 0;
	strcat(ttt,"\"");
	strcat(ttt,literal);
	strcat(ttt,"\"+(");
	strcpy(literal,ttt);

	char *p = ttt;
	char *q = p + strlen(p);
	while(q > p)
		unput(*--q);
	}
<STRING_X>\" { 
	BEGIN(INITIAL);
	yylval.uString = (char*)malloc(sizeof(char)*strlen(literal)+1);
	strcpy(yylval.uString,literal);
	return STRING;
    }	
\' { literal[0] = 0;
    BEGIN(STRING2);
    }
<STRING2>[^\\\n\']+ strcat(literal,yytext);
<STRING2>\\n strcat(literal,"\n");
<STRING2>\\\' strcat(literal,"\'");
<STRING2>\' {
	BEGIN(INITIAL);
	yylval.uString = (char*)malloc(sizeof(char)*strlen(literal)+1);
	strcpy(yylval.uString,literal);
	return STRING;
    }
\} {
	literal[0] = 0;
	strcat(literal,")+\"");
	char *p = literal;
	char *q = p + strlen(p);
	while(q > p)
		unput(*--q);
	literal[0] = 0;
	
    }
\}\" {
		unput(')');
	}

";" return ';';
"." return '.';
"," return ',';
"[" return '[';
"]" return ']';
"(" return '(';
")" return ')';
"+" return '+';
"-" return '-';
"*" return '*';
"/" return '/';
"=" return '=';
"==" return EQUAL;
"<" return '<';
">" return '>';
"!=" return NOTEQUAL;
"||" return OR;
"&&" return AND;
"!" return '!';

0b[01]([01_]*[01])? {
    int i, len = 0;
	long result;
	char *stop;
    for(i = 2; i < strlen(yytext); i++)
	    if(yytext[i] != '_')
            temp[len++] = yytext[i];
    temp[len] = '\0';
	result = strtol(temp, &stop, 2);
    //printf("%s => %ld\t\tbin constant\n", temp, result);
	yylval.uInt = result;
	return INT;
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
   // printf("%s => %d\t\thex constant\n", temp, result);
    yylval.uInt = result;
	return INT;
    }
0[0-7]([0-7_]*[0-7])? {
    int i, len = 0;
	int result;
    for(i = 0; i < strlen(yytext); i++)
	    if(yytext[i] != '_')
            temp[len++] = yytext[i];
    temp[len] = '\0';
	sscanf(temp, "%o", &result);
    //printf("%s => %d\t\toct constant\n", temp, result);
	yylval.uInt = result;
	return INT;
    }
[0-9]([0-9_]*[0-9])? {
    int i, len = 0;
	int result;
    for(i = 0; i < strlen(yytext); i++)
	    if(yytext[i] != '_')
            temp[len++] = yytext[i];
    temp[len] = '\0';
	sscanf(temp, "%d", &result);
    //printf("%s => %d\t\tdec constant\n", temp, result);
	yylval.uInt = result;
	return INT;
    }
{IDENTIFIER} {
	yylval.uId = (char*)malloc(sizeof(char) * strlen(yytext));
	strcpy(yylval.uId, yytext);
	return ID;
}
"$"{IDENTIFIER} {
	yylval.uId = (char*)malloc(sizeof(char) * strlen(yytext));
	strcpy(yylval.uId, yytext);
	return ID;
}
"@"{IDENTIFIER} {
	yylval.uId = (char*)malloc(sizeof(char) * strlen(yytext));
	strcpy(yylval.uId, yytext);
	return IDFIELD;
}
"@@"{IDENTIFIER} {
	yylval.uId = (char*)malloc(sizeof(char) * strlen(yytext));
	strcpy(yylval.uId, yytext);
	return ID_STATIC_FIELD;
}
{IDENTIFIER}"?" {
	yylval.uId = (char*)malloc(sizeof(char) * strlen(yytext));
	strcpy(yylval.uId, yytext);
	return ID;
}
{IDENTIFIER}"!" {
	yylval.uId = (char*)malloc(sizeof(char) * strlen(yytext));
	strcpy(yylval.uId, yytext);
	return ID;
}

[\n]+ return EOL;
[\n]+([[:blank:]]+|[\n]+)+ return EOL;

[[:blank:]]+

. printf("Error, unexpected lexem %s !!!!!!\n", yytext);

%%



