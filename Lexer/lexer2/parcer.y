%{
#include <stdio.h>
#include <malloc.h>

void yyerror(char const *s);
extern int yylex(void);

%}

%token INT
%token STRING
%token EOL
%token DEF
%token END
%token WHILE
%token DO
%token UNTIL
%token CLASS
%token SELF
%token SUPER
%token RETURN
%token ID_CAP 
%token ID_LOW
%token ID_FUNC // С ! или ? на конце
%token ID_VAR_FIELD // С @
%token EQUAL
%token NOTEQUAL
%token OR
%token AND
%token NIL
%token TRUE
%token FALSE
%token IF
%token ELSIF
%token ELSE
%token UNLESS
%token THEN

%left OR
%left AND
%left EQUAL NOTEQUAL
%right '='
%left '<' '>'
%left '-' '+'
%left '*' '/'
%left '!' UMINUS
%left '.'
%left ']' '['
%nonassoc UBR

%nonassoc ')'


/*
%type id
%type eln
%type expr
%type stmt
%type stmt_seq
%type stmt_seqE
%type method_call
%type method_def
%type method_def_param
%type method_def_param_seq
%type method_def_param_seqE
%type while_stmt
%type until_stmt
%type class_def
%type program
%type array*/
%%



program		: stmt_seq;

eln			: /*empty*/
			| EOL 
			;
	
id			: ID_CAP
			| ID_LOW
			| ID_FUNC
			| ID_VAR_FIELD
			;
	
expr		: expr '+' eln expr
			| expr '-' eln expr
			| expr '*' eln expr
			| expr '/' eln expr
			| expr '<' eln expr
			| expr '>' eln expr
			| expr EQUAL eln expr
			| expr NOTEQUAL eln expr
			| expr OR eln expr
			| expr AND eln expr
			| '!' expr
			| expr '=' eln expr
			| '-' expr %prec UMINUS
			| '(' eln expr eln ')'
			| expr '[' eln expr eln ']'
			| '[' eln expr_seq eln ']' %prec UBR
			| INT
			| STRING
			| id
			| NIL
			| TRUE
			| FALSE
			| expr '.' id
			| expr '.' id '(' expr_seq ')'
			| SELF
			| SUPER
			;
	
expr_seq	: /* empty */
			| expr_seqE
			;
	
expr_seqE	: expr
			| expr_seq ',' expr
			;

stmt		: /*empty*/
			| expr
			| method_def
			| class_def
			| while_stmt
			| until_stmt
			| RETURN expr_seq
			| if_stmt
			| unless_stmt
			;

stmt_seq    : stmt
			| stmt_seq EOL stmt
			;
	
method_def	: DEF eln id '(' method_def_param_seq eln ')'  stmt_seq  END
			| DEF eln id method_def_param_seq EOL stmt_seq END
			;

method_def_param_seq: /* empty */
			| method_def_param_seqE
			;

method_def_param_seqE: ID_LOW
			| method_def_param_seq ',' eln ID_LOW
			;

while_stmt	: WHILE eln expr DO stmt_seq END
			| WHILE eln '(' eln expr eln ')' EOL stmt_seq END
			;
	
until_stmt	: UNTIL eln expr DO stmt_seq END
			| UNTIL eln '(' eln expr eln ')' EOL stmt_seq END
			;

elsif_seq	: /* empty */
			| elsif_seqE
			;
					
elsif_seqE	: ELSIF expr THEN stmt_seq
			| elsif_seqE ELSIF expr THEN stmt_seq 
			;
			
if_stmt		: IF eln expr eln THEN stmt_seq elsif_seq END
			| IF eln expr eln THEN stmt_seq elsif_seq ELSE stmt_seq END
			;

unless_stmt	: UNLESS eln expr eln THEN stmt_seq END
			| UNLESS eln expr eln THEN stmt_seq ELSE stmt_seq END
			;
			
class_def	: CLASS eln ID_CAP '<' eln ID_CAP EOL stmt_seq END
			| CLASS eln ID_CAP EOL stmt_seq END
			;


%%
%error-verbose
void yyerror(char const *s)
{
 printf("%s",s);
}

