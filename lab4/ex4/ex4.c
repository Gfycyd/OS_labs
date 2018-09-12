#include <stdio.h>
#include <stdlib.h>

#include <string.h>

int shell(){

    char command[20];
    while (1){
        printf("User Katya:");
        fgets(command,100,stdin);;
 	int size = strlen(command);
 	command[size-1]='\0';
        if (strcmp(command, "close") == 0){
            return 0;
        } else
            system(command);
	printf("\n");
    }
}
int main(void) {
    shell();
    return 0;
}