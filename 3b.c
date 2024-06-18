#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <time.h>
#include<sys/stat.h>
int main(){
	struct dirent *dir;
	struct stat fs;
	DIR *dp;

	dp=opendir(".");
	if(dp){
		while((dir=readdir(dp))!=NULL){
			stat(dir->d_name,&fs);
			printf("%ld  %o  %d  %d  %s %s",fs.st_ino,fs.st_mode,fs.st_uid,fs.st_gid,ctime(&fs.st_atime),dir->d_name);
		printf("\n");
		}}
return 0;
}
