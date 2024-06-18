#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main(int argc, char* argv[]){
       if(argc!=2){
       perror("Source Command\n");
	exit(EXIT_FAILURE);
       }
	pid_t pid=fork();
 if(pid<0){
 perror("Fork Failed\n");
exit(EXIT_FAILURE);
 }

 else if(pid==0){
execl("/bin/sh","sh","-c",argv[1],NULL);

_exit(EXIT_FAILURE);
 }
 else{
	 int status;
	 if(waitpid(pid,&status,0)==-1){
		 perror("wait failed\n");
		 return -1;
	 }else{printf("Command Exected\n");
		 return status;}}}
