#include <stdio.h>
#include "ass4_16CS30027.tab.h"

int main() 
{ 
	yydebug =1;
  int i=yyparse();
  printf("\n++++++++++++Parser result:++++++++++++\n");
  if(i) printf("Failure!\n");
  else printf("Success!\n");
  return 0;
 }