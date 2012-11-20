typedef union
{
	int uInt;
	char* uId;
	char* uString;
	struct ExprNode* uExpr;
	struct ExprSeqNode* uExprSeq;
	struct StmtNode* uStmt;
	struct StmtSeqNode* uStmtSeq;
	struct MethodDefParamSeqNode* uMethodDefParamSeq;
	struct MethodDefParamNode* uMethodDefParam;
	struct ProgramNode* uProgram;
	struct ElsifSeqNode *uElsifSeq;
} YYSTYPE;
#define	INT	258
#define	STRING	259
#define	EOL	260
#define	DEF	261
#define	END	262
#define	WHILE	263
#define	DO	264
#define	UNTIL	265
#define	CLASS	266
#define	SELF	267
#define	SUPER	268
#define	RETURN	269
#define	ID	270
#define	EQUAL	271
#define	NOTEQUAL	272
#define	OR	273
#define	AND	274
#define	NIL	275
#define	TRUE	276
#define	FALSE	277
#define	IF	278
#define	ELSIF	279
#define	ELSE	280
#define	UNLESS	281
#define	THEN	282
#define	UMINUS	283
#define	UBR	284


extern YYSTYPE yylval;
