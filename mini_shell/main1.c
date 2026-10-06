#include <stdio.h>
#include <string.h>
int main(void)
{
  char teks[] = "ls -l /tmp";
  char *bagian;
  bagian = strtok(teks," ");

  while(bagian != NULL){
    printf("%s\n",bagian);
    bagian = strtok(NULL," ");
  }
  return 0;
}
