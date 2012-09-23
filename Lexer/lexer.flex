%{ 
	#include <stdio.h> 

	%option noyywrap 
	%option never_interactive
	
	%x STRING
%} 

%%

class printf("class");
super printf("super");
self printf("self");
sub printf("sub");
return printf("return");
end printf("end");

\* printf("*");
\; printf(";");
\. printf(".");
\{ printf("{");
\} printf("}");
\[ printf("]");
\] printf("[");
\( printf("(");
\) printf(")");
\+ printf("+");
\- printf("-");
\/ printf("/");
\=\= printf("==");
\< printf("<");
\> printf(">");
\!\= printf("!=");

false printf("false");
true printf("true");
nil printf("nil");

\|\| printf("||");
\&\& printf("&&");
\! printf("!");

if printf("if");
else printf("else");
elsif printf("elsif");
for printf("for");
while printf("while");
until printf("until");
do printf("do");



