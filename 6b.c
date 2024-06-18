#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc,char* argv[]){
	int fd;
char buffer[51];
	struct flock fvar;
	if(argc!=2){
		printf("Source <filename>\n");
		exit(-1);
	}
	
	fd = open(argv[1],O_RDWR);
	fvar.l_type=F_WRLCK;
	fvar.l_whence=SEEK_END;
	fvar.l_start=-100;
	fvar.l_len=100;


	printf("PRESS ENTER TO SET THE LOCK>>>\n");
	getchar();
	printf("TRYIGNTO GET THE LOCK>>>\n");

	if(fcntl(fd,F_SETLK,&fvar)==-1){
		fcntl(fd,F_GETLK,&fvar);
		printf("Process is already locked by process with PID: %d\n",fvar.l_pid);
		close(fd);
		return -1;
	}

	printf("Locked\n");

	lseek(fd,-50,SEEK_END);

	
	int n = read(fd,buffer,50);
	buffer[n]='\0';
	printf("LAST 50 BYTES:\n");
	puts(buffer);

	  printf("PRESS ENTER TO SET THE UNLOCK>>>\n");
        getchar();
	fvar.l_type=F_UNLCK;
	fcntl(fd,F_SETLK,&fvar);
	puts("Unlocked");
	return 0;
}





