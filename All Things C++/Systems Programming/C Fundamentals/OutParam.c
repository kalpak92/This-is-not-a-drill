#include <stdio.h>   // for printf, sscanf
#include <stdlib.h>  // for strtol, EXIT_SUCCESS

int main(int argc, char** argv) {
    int   num;       // holds return values
    char* pEnd;      // holds endPtr output param for strtol
    char* str1 = "333 rocks";
    int   i;         // output param for sscanf
    char  str2[10];  // output param for sscanf

    num = (int) strtol(str1, &pEnd, 10);
    printf("*** STRTOL ***\n");
    printf("converted number = %d\n",num);
    printf("str1 = %p\n",str1);
    printf("pEnd = %p\n\n",pEnd);

    num = sscanf("3 blind mice","%d %s",&i,str2);
    printf("*** SSCANF ***\n");
    printf("filled %d arguments\n",num);
    printf("i = %d\n",i);
    printf("str2 holds: %s\n",str2);

    return EXIT_SUCCESS;
}