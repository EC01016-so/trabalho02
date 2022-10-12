#include <unistd.h>



int main()
{

    char *ls = "ls";
    char *argn1 = "-l";
    char *argm2 = "-s";

    //Usamos chamanda de sistema execlp para executar comando 'ls' no terminals para lista arquivos que 
    // está em uma pastar.
    execlp(ls, ls, argn1, argm2, NULL);

    return 0;
}