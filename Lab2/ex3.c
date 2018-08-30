#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char* argv[])
{
	int n = atoi(argv[1]);		

	int max = 2*n - 1;

	char** strings = (char**) malloc(n * sizeof(char*));
	
	for( int i = 0; i < n; i++)
	{ 
	    
	    strings[i] = (char*)malloc(max * sizeof(char));
		for(int j = 0; j < max; j++)
			strings[i][j] = ' ';
			
	}

	for (int  i = 0; i < n;i++)
	{
		for(int j = n - i; j <=n + i;j++)
			strings[i][j] = '*';
		
		printf(strings[i]);
		printf("\n");
	}     
}

