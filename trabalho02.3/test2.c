# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <dirent.h>
# include <unistd.h>



char *string_anexar(char *str1, char *str2);
char *troca_nome();

int main()

{
    struct dirent *d;
    DIR *dir = opendir(".");

    int num_arq = 0;
    
    while ((d = readdir(dir))) {
        printf("%s\n", d->d_name); 
        if(strlen(d->d_name) != 3 && strlen(d->d_name) != 4)
        {
            num_arq++;
        }
        //printf("%d\n", num_arq);
    }
    printf("num_arq: %d\n", num_arq);

    for(int i = 0; i < num_arq; i++)
    {
        printf("%d\n", num_arq);
        troca_nome();
    }

    return 0;

}

char *troca_nome()
{
    struct dirent *d;
    DIR *dir = opendir(".");

    char *path = "./";
    char *L = "./L";
    char *argls1;
    char *argls2 ;
    char *mv = "mv";
    int i = 0;

  
    while ((d = readdir(dir))!= NULL) 
    {

        argls1 = string_anexar(path, d->d_name);

        argls2 = string_anexar(L, d->d_name);

        printf("%s e %s\n", argls1, argls2);

        if(strlen(argls1) != 3 && strlen(argls1) != 4)
        {
            printf("%d\n", i++);
            execlp(mv, mv, argls1, argls2, NULL);
        }

        //porque a nova string resultante é armazenada no heap, precisamos lembrar
        // para usar free() quando terminarmos com a string
        free(argls1);
        free(argls2);
    }

}

//Retorna uma nova string no heap contendo o resultado da adição de str2 a str1.
char *string_anexar(char *str1, char *str2)
{
    //Crie espaço para uma nova matriz de caracteres (string) no heap grande o suficiente para conter
    // os caracteres em s1 e s2 E um terminador nulo
    int len = strlen(str1);
    int len2 = strlen(str2);
    int tamanho = len + len2 + 1;
    char *s = calloc(tamanho, sizeof(char));
    
    //Copie str1 em s
    for (int i = 0; i <len; i++)
    {
        s[i] = str1[i];
    }

    //Copie str2 em s, mas deslocado pelo comprimento de str1 para anexá-lo após s1!
    for (int i = 0; i < len2; i++)
    {
        s[len + i] = str2[i];

        //coloque o terminador nulo para terminar a string
        s[tamanho - 1] = '\0';
    
    }

    return s;
}
