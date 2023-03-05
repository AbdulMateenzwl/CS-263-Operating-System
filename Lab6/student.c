#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
  int pipefds[2];
  char buffer[14];
  char c[] = "HELLO WORLD";
  if (pipe(pipefds) == -1)
  {
    perror("pipes");
    exit(EXIT_FAILURE);
  }
  else
  {
    write(pipefds[1], c, 11);
    read(pipefds[0], buffer, 11);
  }
  printf("%s", buffer);
  return EXIT_SUCCESS;
}
