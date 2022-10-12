# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>


int main(int argc, char **argv){
    // Criando variavel int 
    int lista[2], concatena;
    // Criando variable char
    // variavel que recebe os nomes dos arquivos
    char *lista_07_09 = "lista_07_09.txt";
    char *lista_08_09 = "lista_08_09.txt";
    /* variavel que recebe o nome de arquivo que vai ser criado no 
    final do excusao
    */
    char *concatenado = "arquivo_concatenado.txt";
    int tamanho = 2;
    char buf[100];
    // Abrindo o arquivo com somente letura
    lista[0] = open(lista_07_09, O_RDONLY);
    lista[1] = open(lista_08_09, O_RDONLY);
    /*Abrir o arquivo com somente escrever, acrescentar e se o arquivo naõ foi 
    crear novo arquivo   */
    concatena = open(concatenado, O_WRONLY |O_APPEND | O_CREAT, 0644);

    // um loop para escrever na arquivo "arquivo_concatenado.txt"
    if (lista[0] != -1 || lista[1] != -1 || concatena != -1){
        for (int i=0; i<tamanho; i++){
            read(lista[i], buf, sizeof(buf));
            write(concatena, ("%c \n", buf), strlen(buf)); 
            lseek(concatena, 0, SEEK_END);
        }
        // fechar os arquivos que foram abertos 
        close(lista[0]);
        close(lista[1]);
        close(concatena);

        printf("concatena de 'lista_07_09.txt' e 'lista_08_09.txt' foi Sucesso\n\n");
        printf("Arquivo 'lista_07_09.txt'\n");
        printf("----------------------------------------------------------------------------------------\n");
        system("cat lista_07_09.txt");
        printf("****************************************************************************************\n \n");
        printf("Arquivo 'lista_08_09.txt'\n");
        printf("----------------------------------------------------------------------------------------\n");
        system("cat lista_08_09.txt");
        printf("****************************************************************************************\n \n");
        printf(" Arquivo concatenado\n");
        printf("----------------------------------------------------------------------------------------\n");
        system("cat arquivo_concatenado.txt");
        printf("****************************************************************************************\n \n");
        

    }else{
        // print na telar se o corre erros 
        printf("Falha ao abrir arquivo\n");
    }

    return 0;
}