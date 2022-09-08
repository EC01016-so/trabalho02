# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>


int main(int argc, char **argv){
    int lista[2], concatena;
    char *lista_07_09 = "lista_07_09.txt";
    char *lista_08_09 = "lista_08_09.txt";
    char *concatenado = "arquivo_concatenado.txt";
    int meu;
    int tamanho = 2;
    char c[50];
    
    lista[0] = open(lista_07_09, O_RDONLY);
    lista[1] = open(lista_08_09, O_RDONLY);
    concatena = open(concatenado, O_WRONLY |O_APPEND | O_CREAT, 0644);
    //printf("lista_1= %d", lista_1);
    if (lista[0] != -1 || lista[1] != -1 || concatena != -1){
        for (int i=0; i<tamanho; i++){
            read(lista[i], c, sizeof(c));
            write(concatena, ("%c \n", c), strlen(c)); 
            lseek(concatena, 0, SEEK_END);
            printf("lista_1: %d %d\n",sizeof(c), lista[i]);
        }
        close(lista[0]);
        close(lista[1]);
        close(concatena);
    }else{
        printf("open failed\n");
    }

    /*
    //char buf[4096];
    //char *c = (char *) calloc(100, sizeof(char)); 
    //char msg[50] = "como voce esta";
    //int creat(const char *nosso_arquivo, mod);
    lista_1 = open("lista_07_09.txt", O_RDONLY, 0);
    //printf("fd = %d", l);
    if (lista_1!= -1){
        printf("list_07_09.txt foi abrir com sucesso\n");
        write(STDOUT_FILENO, lista_1, sizeof(lista_1));
        //write(fd, msg, sizeof(msg));
        lseek(lista_1, 0, SEEK_SET);
        lista = read(lista_1, c, 10);
        printf("\n %s foi escribir com sucesso\n",  lista);
        close(lista_1);
    }else{
        printf("list_07_09.txt foi abrir com erros\n");
    }*/

    return 0;
}