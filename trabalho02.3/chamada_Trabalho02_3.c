#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Declaração da função "string_anexar"
char *string_anexar(char *str1, char *str2);

int main() {
  
  /* Criação de uma estrutura do tipo dirent, atribuida para a
  variavel "d", que receberá as informações de um diretório*/
  struct dirent *d;
  
  /* Criação de uma variavel tipo "DIR"  que receberá o 
  diretório que será aberto*/
  DIR *dir = opendir(".");
  
  /* Caractere que será inserido na frente do nome dos arquivos */
  char *L = "L";
  
  /* Variavel que receberá o nome do arquivo antes de ser alterado */
  char *argls1;
  /* Variavel que receberá o nome do arquivo depois de ser alterado */  
  char *argls2;
  
  /* Criação de matriz de 2 vetores que armazenará o conteúdo do arquivo
  antes e depois de alterar o nome do arquivo*/
  int lista[2];
  
  /* Variavel que alocará na memória (buffer) um espaço para o
  conteúdo de texto do arquivo que será alterado */
  char buf[1024];

  /* Loop que será executado no diretório corrente que coletará o nome de
  cada arquivo */
  
  while ((d = readdir(dir)) != NULL) {
    
    /* Variavel que armazenará o nome do arquivo antes de ser alterado*/
    argls1 = d->d_name;
    /* Variavel que armazenará o valor da função "string_anexar" após adicionar
    a string "L"*/
    argls2 = string_anexar(L, d->d_name);
    /* Exibe na tela o nome do arquivo antes e depois de ser alterado */
    printf("%s e %s\n", argls1, argls2);

    /* Verificação para arquivos ocultos */
    if (strlen(argls1) != 3 && strlen(argls1) != 4) {

      lista[0] = open(argls1, O_RDONLY);
      
      /* Criando novo arquivo com a string "L" na frente do nome */
      lista[1] = open(argls2, O_WRONLY | O_APPEND | O_CREAT, 0644);

      /* Condição que verifica se o arquivo original (antes de ser modificado)
      foi aberto e se novo arquivo (com a string "L") foi criado */
      
      if (lista[0] != -1 || lista[1] != -1) {
        read(lista[0], buf, sizeof(buf));
        write(lista[1], ("%c \n", buf), strlen(buf));
        lseek(lista[1], 0, SEEK_END);
        
        // Fecha os arquivos que foram abertos
        close(lista[0]);
        close(lista[1]);
      } 
      /* Caso o arquivo não possa ser aberto ou caso não seja possível criar
      um novo arquivo, o else é executado*/
      else {
        // Exibe na tela caso ocorra erro
        printf("Falha ao abrir arquivo\n");
      }
      // Pausa no código por 1s
      sleep(1);

      //"O arquivo com o nome anterior (sem a string "L") é excluído"
      if (remove(argls1) == 0) {
      } else {
        printf("Erro no exclusão do arquivo.");
      }
    }
    // É feita a limpeza da memória para liberar o espaço alocado na memória
    free(argls2);
  }
  return 0;
}

/* Função "string_anexar" que retorna uma nova string armazenado no buffer
contendo o resultado da adição de str1 (string "L") e str2 (nome do arquivo). */
char *string_anexar(char *str1, char *str2) {
  /* Cria espaço para uma nova matriz de caracteres (string) no "heap" (estrutura)
  grande o suficiente para conter os caracteres em str1 e str2 e um terminador nulo
  para indicar o fim da linha*/
  
  // Variaveis que armazenarão o tamanho dos nomes (número de caracteres) 
  int len = strlen(str1);
  int len2 = strlen(str2);
  
  // Soma dos números de caracteres das variaveis, junto com "1" que é o terminador nulo
  int tamanho = len + len2 + 1;
  
  // Cálculo de bits necessários para alocar os caracteres na memória
  char *s = calloc(tamanho, sizeof(char));

  /* Loop para que str1 (string "L") seja armazenada em "s" no espaço alocado na memória */
  for (int i = 0; i < len; i++) {
    s[i] = str1[i];
  }

  /* Loop para que str1 + str2 seja armazenada em "s" no espaço alocado na memória */
  for (int i = 0; i < len2; i++) {
    s[len + i] = str2[i];
  }
  // O terminador nulo é inserido para terminar a string
  s[tamanho - 1] = '\0';
  
  // Retorna o nome do arquivo alterado 
  return s;
}
