// belajar mini shell
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
int main(void) {
  char input_user[100];
  char *argv[10];

  while (1) {
    printf("Mini-shell>> ");
    fflush(stdout);

    if (fgets(input_user, sizeof(input_user), stdin) == NULL) {
      break;
    }
    input_user[strcspn(input_user, "\n")] = '\0';

    int i = 0;
    char *bagian = strtok(input_user, " ");

    while (bagian != NULL && i < 9) {
      argv[i] = bagian;
      i++;

      bagian = strtok(NULL, " ");
    }
    argv[i] = NULL;

    if(argv[0] == NULL){
      continue;
    }

    //exit program
    //strcmp adalah pembanding dua parameter

    if((strcmp(argv[0],"exit") == 0) || (strcmp(argv[0],"Exit") == 0)){
      break;
    }
    pid_t pid1 = fork();
    if (pid1 < 0) {
      perror("pid1 gagal");
      return 1;
    }
    if (pid1 == 0) {
      execvp(argv[0],argv);
      perror("execvp error");
      return 1;
    }
    waitpid(pid1, NULL, 0);
  }

  return 0;
}
