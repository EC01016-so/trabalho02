# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <fcntl.h>

int main(){
    int fd;
    char buf[80];
    char msg[50] = "como voce esta";
    //int creat(const char *nosso_arquivo, mod);
    fd = open("nosso_arquevo.txt", O_RDWR | O_CREAT );
    printf("fd = %d", fd);
    if (fd != -1){
        printf("nosso_arquevo.txt foi abrir com sucesso\n");
        write(fd, msg, sizeof(msg));
        lseek(fd, 0, SEEK_SET);
        read(fd, buf, sizeof(msg));
        printf("\n %s foi escribir com sucesso\n", buf);
        close(fd);
    }else{
        printf("nosso_arquevo.txt foi abrir com erros\n");
    }
    return 0;
}