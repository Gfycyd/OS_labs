

#include "stdio.h"
int main(int argc, const char * argv[]) {
    // insert code here...
    int integer;
    float floater;
    double doubles;
    integer = __INT_MAX__;
    floater = __FLT_MAX__;
    doubles = __DBL_MAX__;
    printf("Value of Max Int: %d . Size of this (bytes) : %ld \n", integer, sizeof(integer));
    printf("Value of Max Float: %f. Size of this (bytes) : %ld \n ", floater, sizeof(floater));
    printf("Value of Max Double: %f. Size of this (bytes) : %ld ", doubles, sizeof(doubles));
    
    return 0;
}
