
#include <stdio.h>
#include <string.h>
int main(int argc, const char * argv[])
{
	char str [1000], str2 [1000] = "";
	printf("Write string, which yoour prefer: \n");
	scanf("%s", str);
	printf("%d",strlen(str));
	for ( int i = 0; i < strlen(str); i ++ ){
		str2[i] = (str[strlen(str) - i - 1]);
}	
    char *p = str2;
    printf("String in reverse : %s" , str2);
	return 0;
}
