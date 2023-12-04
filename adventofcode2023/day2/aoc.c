#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
    FILE *fp = argc == 3 ? fopen(argv[1], "r") : stdin;
    if (!fp){
        perror("fopen");
        exit(1);
    }
    char buf[256];
    while (fgets(buf,sizeof(buf),fp) != NULL){
        int linelen = strlen(buf);

    }

    return 0;
}
