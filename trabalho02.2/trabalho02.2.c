#include <unistd.h>

int main()
{
    char *ls = "ls";
    char *argn1 = "-l";
    char *argm2 = "-s";

    /* Usamos a chamada de sistema execlp para executar comando 'ls'
    no terminal para listar arquivos que estão em um diretório. */
    
    execlp(ls, ls, argn1, argm2, NULL);

    return 0;
}
