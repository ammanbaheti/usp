#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
//#include<sys/stats.h>
#include<fcntl.h>
#include<dirent.h>

int main(){
	struct dirent *dir;
	DIR *dp;
	int fd ,n;

	dp = opendir(".");
	if(dp){
		while((dir=readdir(dp))!=NULL){
			fd=open(dir->d_name,O_RDWR,0777);
			n = lseek(fd,0,SEEK_END);
			if(!n){
				printf("Deleting File: %s\n",dir->d_name);
				unlink(dir->d_name);
			}
		}
	}
}
