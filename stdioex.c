#include <stdio.h>
#include "stdioex.h"
char get1char(){
fflush(stdin);
char ret = getchar();
return ret;
}
