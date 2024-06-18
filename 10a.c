#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <syslog.h>
void create_daemon(){
	pid_t pid = fork();
	if(pid<0){

	}
	else if(pid>0){

	}

	if(setsid()<0){
		exit(EXIT_FAILURE);
	}
	umask(0);
	if(chdir("/")<0){
		exit(EXIT_FAILURE);
	}
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);

	open("/dev/null", O_RDONLY); // stdin
	open("/dev/null", O_WRONLY); // stdout
	open("/dev/null", O_WRONLY); // stderr
}
int main(){
	create_daemon();
	openlog("daemon_process",LOG_PID,LOG_DAEMON);
	while(1){
		syslog(LOG_NOTICE,"DAEMON IS RUNNING >>>");
		sleep(10);
	}
	closelog();
	return EXIT_SUCCESS;
}
