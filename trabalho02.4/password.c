#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  char *buf;
  char *pw = "passwd";

  buf = (char *)malloc(10 * sizeof(char));
  buf = getlogin();

  printf("\n Você está  trocando o password de um usuário: %s \n", buf);

  execlp(pw, pw, buf, NULL);

  return 0;
}
