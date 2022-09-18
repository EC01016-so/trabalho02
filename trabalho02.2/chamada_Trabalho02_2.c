# include <unistd.h>

int main(){
    char *mv = "mv";
    char *arg1 = "./lista_07_09.txt";
    char *arg2 = "./Llista_07_09.txt";
    execlp(mv, mv, arg1, arg2, NULL);
    return 0;
}