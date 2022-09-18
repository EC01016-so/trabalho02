#include <unistd.h>



int main()
{

    char *ls = "ls";
    char *argn1 = "-l";
    char *argm2 = "-s";

    execlp(ls, ls, argn1, argm2, NULL);

    return 0;
}