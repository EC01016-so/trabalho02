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
    
    // Criando variavel char  
    // Variaveis que receberão os nomes dos arquivos
    char *lista_07_09 = "lista_07_09.txt";
    char *lista_08_09 = "lista_08_09.txt";
    /* variavel que recebe o nome de arquivo que vai ser criado no 
    final do execução */
    char *concatenado = "arquivo_concatenado.txt";
    /* Variavel que alocará na memória (buffer) um espaço para o
    conteúdo de texto dos arquivos que serão concacetenados */
    char buf[100];
    
    // Abrindo os arquivos somente no modo leitura
    lista[0] = open(lista_07_09, O_RDONLY);
    lista[1] = open(lista_08_09, O_RDONLY);
    // Criando novo arquivo para a concatenação
    concatena = open(concatenado, O_WRONLY |O_APPEND | O_CREAT, 0644);

      /* Condição que verifica se os arquivos foram abertos e se o 
      arquivo concatenado foi criado */
      if (lista[0] != -1 || lista[1] != -1 || concatena != -1){
        for (int i=0; i<2; i++){
            read(lista[i], buf, sizeof(buf));
            write(concatena, ("%c \n", buf), strlen(buf)); 
            lseek(concatena, 0, SEEK_END);
        }
        // Fecha os arquivos que foram abertos 
        close(lista[0]);
        close(lista[1]);
        close(concatena);
        
        // Exibição dos arquivos e resultados
        printf("Concatenação de 'lista_07_09.txt' e 'lista_08_09.txt'\n\n");
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
        // Exibe na tela caso ocorra erro
        printf("Falha ao abrir arquivo\n");
    }

    return 0;
}
