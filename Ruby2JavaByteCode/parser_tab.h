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
#define	IDFIELD	271
#define	EQUAL	272
#define	NOTEQUAL	273
#define	OR	274
#define	AND	275
#define	NIL	276
#define	TRUE	277
#define	FALSE	278
#define	IF	279
#define	ELSIF	280
#define	ELSE	281
#define	UNLESS	282
#define	THEN	283
#define	UMINUS	284
#define	UBR	285


extern YYSTYPE yylval;
