#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *string_anexar(char *str1, char *str2);

int main() {
  struct dirent *d;
  DIR *dir = opendir(".");

  char *path = NULL;
  char *L = "L";
  char *argls1;
  char *argls2;
  int i = 0;

  int lista[2];
  char buf[1024];

  while ((d = readdir(dir)) != NULL) {

    argls1 = d->d_name;

    argls2 = string_anexar(L, d->d_name);

    printf("%s e %s\n", argls1, argls2);

    if (strlen(argls1) != 3 && strlen(argls1) != 4) {

      lista[0] = open(argls1, O_RDONLY);
      /*Abrir o arquivo com somente escrever, acrescentar e se o arquivo naõ foi
      crear novo arquivo   */
      lista[1] = open(argls2, O_WRONLY | O_APPEND | O_CREAT, 0644);

      // um loop para escerver na arquivo "arquivo_concatenado.txt"
      if (lista[0] != -1 || lista[1] != -1) {
        read(lista[0], buf, sizeof(buf));
        write(lista[1], ("%c \n", buf), strlen(buf));
        lseek(lista[1],