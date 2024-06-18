#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2;
    int status;

    // Create the first child process
    pid1 = fork();
    if (pid1 < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid1 == 0) {
        // First child process
        printf("First child (PID: %d) is sleeping for 2 seconds...\n", getpid());
        sleep(2);
        printf("First child (PID: %d) exiting with status 2.\n", getpid());
        exit(2);
    }

    // Create the second child process
    pid2 = fork();
    if (pid2 < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid2 == 0) {
        // Second child process
        printf("Second child (PID: %d) is sleeping for 4 seconds...\n", getpid());
        sleep(4);
        printf("Second child (PID: %d) exiting with status 4.\n", getpid());
        exit(4);
    }

    // Parent process
    pid_t wait_pid = wait(&status);

    if(wait_pid<0){
	    perror("wait");
    }
    else{
	    printf("Parent: Child with pid %d finished\n",wait_pid);
	    printf("Status Code: %d\n",WEXITSTATUS(status));
    }
 wait_pid = waitpid(pid2,&status,0);

    if(wait_pid<0){
            perror("waitpid");
    }
    else{
            printf("Parent: Child with pid %d finished\n",wait_pid);
            printf("Status Code: %d\n",WEXITSTATUS(status));
    }	
    return 0;
}

