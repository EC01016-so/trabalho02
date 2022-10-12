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
        lseek(lista[1], 0, SEEK_END);
        // fechar os arquivos que foram abertos
        close(lista[0]);
        close(lista[1]);
      } else {
        // print na telar se o corre erros
        printf("Falha ao abrir arquivo\n");
      }
      sleep(1);


      //"É para excluído que foi renomiado.
      if (remove(argls1) == 0) {
      } else {
        printf("Erro no excluído.");
      }
    }

    // porque a nova string resultante é armazenada no heap, precisamos lembrar
    //  para usar free() quando terminarmos com a string
    // free(argls1);
    free(argls2);
  }

  return 0;
}

// Retorna uma nova string no heap contendo o resultado da adição de str2 a
// str1.
char *string_anexar(char *str1, char *str2) {
  // Crie espaço para uma nova matriz de caracteres (string) no heap grande o
  // suficiente para conter
  //  os caracteres em s1 e s2 E um terminador nulo
  int len = strlen(str1);
  int len2 = strlen(str2);
  int tamanho = len + len2 + 1;
  char *s = calloc(tamanho, sizeof(char));

  // Copie str1 em s
  for (int i = 0; i < len; i++) {
    s[i] = str1[i];
  }

  // Copie str2 em s, mas deslocado pelo comprimento de str1 para anexá-lo após
  // s1!
  for (int i = 0; i < len2; i++) {
    s[len + i] = str2[i];

    // coloque o terminador nulo para terminar a string
    s[tamanho - 1] = '\0';
  }

  return s;
}
