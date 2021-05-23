#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


/*색상*/
#define COLOR_YELLOW "\x1B[33m"
#define COLOR_RESET "\x1B[0m"
#define MAX_LEN_LINE    100

int main(void)
{
    char* getcwd( char* buf, size_t bufsize);

    char command[MAX_LEN_LINE];
    char *args[] = {command, NULL};
    int ret, status;
    pid_t pid, cpid;

   
    while (true) {
        char *s;
        int len;
	        
        printf("MyShell $ ");
        s = fgets(command, MAX_LEN_LINE, stdin);
        if (s == NULL) {
            fprintf(stderr, "fgets failed\n");
            exit(1);
        }
        
        len = strlen(command);
        printf("%d\n", len);
        if (command[len - 1] == '\n') {
            command[len - 1] = '\0'; 
        }
        
         
	/*exit구현*/
         if(!strcmp(command, "exit")){
                 
		  /*색상변경*/
		  printf(COLOR_YELLOW);
		  printf( "exit!!!\n");
		  printf(COLOR_RESET);
                  return -1;
  
         }


	/*ls구현*/
	args[0] = command;
	if (!strcmp(command, "ls")){ 
		args[0] = "/bin/ls";
		
	}
    
 
        pid = fork();
        if (pid < 0) {
            fprintf(stderr, "fork failed\n");
            exit(1);
        } 
        if (pid != 0) {  /* parent */
            cpid = waitpid(pid, &status, 0);
            if (cpid != pid) {
                fprintf(stderr, "waitpid failed\n");        
            }
            printf("Child process terminated\n");
            if (WIFEXITED(status)) {
                printf("Exit status is %d\n", WEXITSTATUS(status)); 
            }
        }
        else {  /* child */
            ret = execve(args[0], args, NULL);
            if (ret < 0) {
                fprintf(stderr, "execve failed\n");   
                return 1;
            }
        } 
    }
    return 0;
}

