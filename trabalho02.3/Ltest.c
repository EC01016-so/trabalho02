# include <unistd.h>
# include <dirent.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>


char *string_anexar(char *str1, char *str2);

int main()
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

    return 0;
}


//Retorna uma nova string no heap contendo o resultado da adição de str2 a str1.
char *string_anexar(char *str1, char *str2