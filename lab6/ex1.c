#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int len(char * str){
	char* c = str;
	while(*c) ++c;
	return c - str;
}
char* string_one = "OS lab now here";
char* string_two = "";
int main(){
	char inbuf[20];
	int fd[2];
	pipe(fd);
	if (pipe(fd) < 0 )
		exit(1);
	write(fd[1], string_one, 20);
	read(fd[0], inbuf, 20);
 	string_two = inbuf;
	printf(string_two);
	printf("\n");
return 0;
}