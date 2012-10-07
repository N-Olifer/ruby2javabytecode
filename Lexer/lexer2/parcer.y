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
%left '<' '>'
%left '-' '+'
%left '*' '/'
%left '!' UMINUS
%left ']'

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
			| SELF
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
			| INT
			| STRING
			| var_id
			| method_call
			| NIL
			| TRUE
			| FALSE
			;

var_id		: var_id_simple
			| var_id '.' var_id_simple
			;
	
var_id_simple: id
			| ID_VAR_FIELD
			;
	
expr_seq	: /* empty */
			| expr_seqE
			;
	
expr_seqE	: expr
			| expr_seq ',' expr
			;

stmt		: expr
			| method_def
			| class_def
			| while_stmt
			| until_stmt
			| RETURN expr_seq
			;

stmt_seq	: /* empty */
			| stmt_seqE
			;

stmt_seqE	: stmt
			| stmt_seq EOL stmt
			;
	
method_call	: method_id '(' expr_seq ')'
			| id '.' method_call
			;
//???????????????????????
	
method_def	: DEF eln method_id '(' method_def_param_seq eln ')' eln stmt_seq eln END
			| DEF eln method_id method_def_param_seq EOL stmt_seq eln END
			;

method_id	: id
			| ID_FUNC
			| SUPER
			;

method_def_param_seq: /* empty */
			| method_def_param_seqE
			;

method_def_param_seqE: ID_LOW
			| method_def_param_seq ',' eln ID_LOW
			;

while_stmt	: WHILE eln expr DO eln stmt_seq eln END
			| WHILE eln '(' eln expr eln ')' EOL stmt_seq eln END
			;
	
until_stmt	: UNTIL eln expr DO eln stmt_seq eln END
			| UNTIL eln '(' eln expr eln ')' EOL stmt_seq eln END
			;
			
elseif_seq	: /* empty */
			| ELSIF eln expr eln THEN stmt_seq eln elsif_seq
			| ELSIF eln expr EOL stmt_seq eln elsif_seq
			;
			
if_stmt		: IF eln expr eln THEN eln stmt_seq eln END
			| IF eln expr EOL eln stmt_seq eln END
			| IF eln expr eln THEN eln stmt_seq eln elseif_seq eln ELSE eln stmt_seq eln END
			| IF eln expr EOL stmt_seq eln elseif_seq eln ELSE eln stmt_seq eln END
			| IF eln expr eln THEN eln stmt_seq eln elseif_seq eln END
			| IF eln expr EOL stmt_seq eln elseif_seq eln END
			;

unless_stmt	: UNLESS eln expr eln THEN eln stmt_seq eln END
			| UNLESS eln expr EOL stmt_seq eln END
			| UNLESS eln expr eln THEN stmt_seq eln ELSE eln stmt_seq eln END
			| UNLESS eln expr EOL stmt_seq eln ELSE eln stmt_seq eln END
			;
			
class_def	: CLASS eln ID_CAP '<' eln ID_CAP EOL stmt_seq eln END
			| CLASS eln ID_CAP EOL stmt_seq eln END
			;

array		: '[' eln expr_seq eln ']'
			;

%%

void yyerror(char const *s)
{
 printf("%s",s);
}

