#include <stdio.h>
#include "stdioex.h"
char get1char(){
fflush(stdin);
char ret = getchar();
fflush(stdin);
return ret;
}
