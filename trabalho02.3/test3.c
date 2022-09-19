# include <unistd.h>
# include <dirent.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>


char *string_anexar(char *str1, char *str2);

int main()
{
    struct dirent *d;
    DIR *dir = opendir("./testArq");

    char *path = NULL;
    char *L = "L";
    char *argls1;
    char *argls2 ;
    char *mv = "mv";
    int i = 0;


  
    while ((d = readdir(dir))!= NULL) 
    {

        argls1 = d->d_name;

        argls2 = string_anexar(L, d->d_name);

        printf("%s e %s\n", argls1, argls2);

        if(strlen(argls1) != 3 && strlen(argls1) != 4)
        {
            printf("%d\n", i++);
            //execlp(mv, mv, argls1, argls2, NULL);
            if(rename(argls1, argls2) != 0)
            {  
                fprintf(stderr, "Errno: %d\n", errno);
                perror("Error msg");
            }else {
                printf("e ");
            }
           sleep(1);
        }

        //porque a nova string resultante é armazenada no heap, precisamos lembrar
        // para usar free() quando terminarmos com a string
        //free(argls1);
        free(argls2);
    }

    return 0;
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
