#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  
  // Variavel que armazenará o nome do usuário
  char *buf;
  // Variavel que receberá o comando, em string, de 'passwd'
  char *pw = "passwd";

  // Alocação na memória do tamanho do nome do usuário (em caracteres)
  buf = (char *)malloc(10 * sizeof(char));
  // Recebe o nome do usuário
  buf = getlogin();
  // Exibe na tela um aviso informando que a senha do usuário será alterado
  printf("\n Você está trocando o 'password' do usuário %s \n", buf);
  // Chamada de sistema para executar a troca da senha
  execlp(pw, pw, buf, NULL);

  return 0;
}
