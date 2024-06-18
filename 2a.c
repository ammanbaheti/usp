#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<time.h>
int main(int argc,char** argv[]){
	struct stat fs;
	if(argc!=2){
		return -1;}

	if(stat(argv[1],&fs)<0){
		return -1;
	}
	printf("File Size : %ld \n Number of links : %ld \n Numbr of Inodes : %ld \n Mode: %o\n Last Modification Time: %s\n",fs.st_size,fs.st_nlink,fs.st_ino,fs.st_mode,ctime(&fs.st_mtime));
	return 0;
}


