#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc,char* argv[]){
	char buffer[100];
	int fd;
	pid_t pid;

	if((fd=open(argv[1],O_RDONLY))<0){
		fprintf(stderr,"Failed to open File\n");
		exit(-1);
	}
	pid = fork();
	if(pid<0){
		printf("Child PRocess Failed\n");
		exit(-1);
	}
        else if(pid==0){
                ssize_t bytesread= read(fd,buffer,5);
                if(bytesread<0){
                        perror("Child Failed to read\n");
                        exit(EXIT_FAILURE);
                }
                buffer[bytesread]='\0';
                printf("Child Read: %s\n",buffer);
                close(fd);  	
	}
	else{wait(NULL);
		
                ssize_t bytesread= read(fd,buffer,5);
                if(bytesread<0){
                        perror("Parent Failed to read\n");
                        exit(EXIT_FAILURE);
                }
                buffer[bytesread]='\0';
                printf("Parent Read: %s\n",buffer);
                close(fd);
	}

	return 0;
}
				
