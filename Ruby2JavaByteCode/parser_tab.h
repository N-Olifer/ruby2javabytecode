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
#define	DEF_STATIC	262
#define	END	263
#define	WHILE	264
#define	DO	265
#define	UNTIL	266
#define	CLASS	267
#define	SELF	268
#define	SUPER	269
#define	RETURN	270
#define	ID	271
#define	IDFIELD	272
#define	ID_STATIC_FIELD	273
#define	EQUAL	274
#define	NOTEQUAL	275
#define	OR	276
#define	AND	277
#define	NIL	278
#define	TRUE	279
#define	FALSE	280
#define	IF	281
#define	ELSIF	282
#define	ELSE	283
#define	UNLESS	284
#define	THEN	285
#define	UMINUS	286
#define	UBR	287


extern YYSTYPE yylval;
