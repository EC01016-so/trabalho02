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
        /