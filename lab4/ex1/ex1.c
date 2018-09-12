#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
   int n = 7;
   int pid = getpid();
   //printf("%d\n", fork());
   fork();
   if (getpid() == pid){
       printf("Hello from parent [%d - %d]\n",pid,n);
   }
   else if (getpid() > pid) {
       printf("Hello from child [%d - %d]\n", getpid(),n);
   }
}