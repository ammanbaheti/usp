#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>

int main(int argc,char * argv[]){
	int source;
	char buf;
	if(argc!=2){
		fprintf(stderr,"Usage <Source>\n");
		exit(-1);
	}
	if((source=open(argv[1],O_RDONLY))<0){
		fprintf(stderr,"CAnt Open File\n");
		exit(-1);
	}
	int size=lseek(source,(off_t)0,SEEK_END);
	printf("FILESIZE:%d\n",size);

	for(int i=size-1;i>=0;i--){
		lseek(source,(off_t) i,SEEK_SET);
		read(source,&buf,1);
		printf("%c",buf);
	}
	printf("\n");
	close(source);
	return 0;

}
