#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char **argv){
    FILE *fp = argc == 3 ? fopen(argv[1], "r") : stdin;
    if (!fp){
        perror("fopen");
        exit(1);
    }
    char part = argv[2][0];
    if (part=='1'){
        printf("solving first part\n");
        char buf[256],first,second;
        char* third;
        int linelen,i,n,cal; 
        cal = 0;
        while (fgets(buf,sizeof(buf),fp) != NULL){
            linelen = strlen(buf);
            i = 0;
            while (!isdigit(buf[i])) i++;
            first = buf[i];
            i = linelen-1;
            while (!isdigit(buf[i])) i--;
            second = buf[i];
            third = (char[]){first,second,'\0'};
            int num = atoi(third);
            cal += num;
        }
        printf("FINALLY THE CAL: %d\n", cal);
    } else {
        printf("solving the second part\n");
        char buf[256];
        int first,second;
        char third[3];
        int linelen,n,cal; 
        cal = 0;
        char nums[9][6] = {"one","two","three","four","five","six","seven","eight","nine"};
        while (fgets(buf,sizeof(buf),fp) != NULL){
            linelen = strlen(buf)-1;
            printf("buf: %s\n",buf);
            for (int i = 0; i < linelen; ++i){
                printf("************buf[%d]: %c\n", i,buf[i]);
                if (isdigit(buf[i])){
                    printf("is digit!\n");
                    first = buf[i]-'0';
                    break;
                } else {
                    int found = 0;
                    for (int j = 0; j < 9; ++j){
                        int l = 0, s = i, wlen = strlen(nums[j]);
                        while (l<wlen && nums[j][l++] == buf[s++]);
                        if (l == wlen){
                            // we found a matching word
                            found = 1;
                            first = j+1;
                        }
                    }
                    if (found) break;
                }
            }
            printf("first: %d and linelen: %d and last buf: %c\n",first,linelen,buf[linelen-1]);
            for (int i = linelen-1; i >= 0 ; --i){
                printf("%d\n",i);
                if (isdigit(buf[i])){
                    second = buf[i]-'0';
                    printf("isdigit: %d\n",buf[i]);
                    break;
                } else {
                    int found = 0;
                    printf("is a letter: %c\n",buf[i]);
                    for (int j = 8; j > -1; --j){
                        int wlen = strlen(nums[j]), s = i, l = wlen-1;
                        printf("j: %d, wlen: %d,nums[j]: %s\n",j,wlen,nums[j]);
                        while (l >= 0){
                            if (nums[j][l] == buf[s]){
                                printf("matched letter: %c with l: %d\n",nums[j][l],l);
                            } else{
                                printf("not match: %c with l: %d\n", nums[j][l],l);
                                break;
                            }
                            l--,s--;
                        }
                        if (l == -1){
                            // we found a matching word
                            second = j+1;
                            printf("found second from words: %s, at pos %d from %s\n",nums[j],s,buf);
                            found = 1;
                            break;
                        } else {
                            printf("didn't match the whole numword: %s from letter: %c\n", nums[j],buf[i]);
                        }
                    }
                    if (found) break;
                }
            }
            printf("-------------------------------------------------------first: %d, second: %d\n", first, second);
            sprintf(third,"%d%d",first,second);
            printf("--------------------------------------third char[]: %s\n", third);
            cal += atoi(third);

            //printf("third: %d\n", atoi(third));
            //int num = atoi(third);
            //cal += num;
        }
        printf("cal: %d",cal);

    }

    return 0;
}
