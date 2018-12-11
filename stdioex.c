#include <stdio.h>
#include "stdioex.h"

void flushStdin(){
while (getchar() != '\n'){}
}

char get1char(){
char ret = getchar();
flushStdin();
return ret;
}
