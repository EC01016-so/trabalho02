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

