//
// Created by Катя on 03.10.2018.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    char **s;
    char foo[] = "Hello World";
    s = (char**) malloc(sizeof(foo));
    *s = foo;
    printf("s is %s\n",*s);
    s[0] = foo;
    printf("s[0] is %c\n",**s);
    return 0;
}
