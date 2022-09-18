# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>


int main(int argc, char **argv){
    // Criando variavel int 
    int lista[2], concatena, filedes = -1, count=0;
    int tamanho = 2;
    char buf[100];
    // Criando variable char
    // variavel que recebe os nomes dos arquivos
    char *arquivo1_em_buf;
    char *arquivo2_em_buf;
    /* variavel que recebe o nome de arquivo que vai ser criado no 
    final do excusao
    */
  
    char *concatenado = "arquivo_concatenado2.txt";

    printf("escreva o caminho do seu primeiro arquivo com sua extensão: \n");
    scanf("%s",arquivo1_em_buf);

    printf("escreva o caminho do seu segundo arquivo com sua extensão: \n");
    scanf("%s",arquivo2_em_buf);  

    // Abrindo o arquivo com somente letura
    lista[0] = open(("%s",arquivo1_em_buf), O_RDONLY);
    lista[1] = open(arquivo2_em_buf, O_RDONLY);
    /*Abrir o arquivo com somente escrever, acrescentar e se o arquivo naõ foi 
    crear novo arquivo   */
    concatena = open(concatenado, O_WRONLY |O_APPEND | O_CREAT, 0644);
    
    // Chama unlink para que sempre que o arquivo seja fechado ou o programa saia
     // o arquivo temporário é deletado

    // um loop para escerver na arquivo "arquivo_concatenado.txt"
    if (lista[0] != -1 || lista[1] != -1 || concatena != -1){
        for (int i=0; i<tamanho; i++){
            read(lista[i], buf, sizeof(buf));
            write(concatena, ("%c \n", buf), strlen(buf)); 
            lseek(concatena, 0, SEEK_END);
        }
        printf("io to aqui\n");
        // fechar os arquivos que foram abertos 
    }else{
        // print na telar se o corre erros 
        printf("Falha ao abrir arquivo\n");
    }

    close(lista[0]);
    close(lista[1]);
    close(concatena);

    return 0;
}