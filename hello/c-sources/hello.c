#include "hello.h"
char *helloworld(char *stri){
   char *tmp = malloc(100);
   sprintf(tmp, "ciao %s!", stri);
   return tmp;
}
