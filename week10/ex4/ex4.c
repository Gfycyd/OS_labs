#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void func(){
	struct dirent *pDirent;
	DIR *dirp;
	dirp = opendir("/home/user/week10/ex4/tmp");
	if (dirp == NULL) { printf("Error" ); return;}
	while ((pDirent = readdir(dirp)) != NULL) {
		char link  [256] = "/home/user/week10/ex4/tmp/";
		char link2 [256];
		strcpy(link2, pDirent->d_name);

		strcat(link,link2);
		
		struct stat buf;
   		int r = stat(link, &buf);
		if ( r < 0 ){
			printf("Some Error");
			return;
		}
		int hard = buf.st_nlink;
		int arr [20];
		if (hard >=2)
			{
				char p [256];
				strcpy(p,(pDirent -> d_name));

				if ( strcmp(p, ".") &&  strcmp(p, "..")){
					printf("%s:   ",p);
					printf("%d\n",buf.st_ino);
				}
			}
	
 }
        closedir (dirp);
}
int main(){
	func();
	return 0;
}