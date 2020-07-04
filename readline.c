#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define READLINE_READ_SIZE 10


char* concate(char* a, char* b, int bLength) { 
    // I pass bLength since b is not null-terminated
    char* c;
    int aLength = strlen(a);
    int newlen = aLength+bLength;
    c = malloc(newlen+1);
    c[0] ='\0';
    strcat(c,a);
    for(int i = 0; i<bLength; i++){
        c[aLength+i] = b[i];
    }
    c[newlen] = '\0';
    return c;
}

char* readline(int fd) {
    static char* buff = "";
    if (strlen(buff)==0) { 
        char* cur;
        cur = (char*)(malloc(READLINE_READ_SIZE));
        int flag = 0;
        int readLength= 0;
        while ((readLength = read(fd, cur, READLINE_READ_SIZE)) > 0) { 
            char* temp = concate(buff, cur,readLength);
            if (strlen(buff)!=0) { 
                // Since I intialize buff, with a way in line 29, I can't just free it, 
                // so I can free it after I mallocing it in concate function, so can you suggest some better ways?
                // Somehow use calloc? but using it with static vars?
                free(buff);
            }
            buff = temp;
            flag = 1;
            if (fd == 0){
                int len = strlen(buff);
                if(buff[len-1]=='\n'){
                    buff[len-1] = '\0';
                    char * res = malloc(len);
                    strcpy(res,buff);
                    buff = "";
                    return res;
                }
            }
        }
        free(cur);
        
        if(!flag) return NULL;

        if (readLength == -1) return NULL;
    }

    int len = strlen(buff);
    char* res;
    res = calloc(len+1,1);
    int p = 0;
    for(int i = 0; i<len; ++i){
        if(buff[i] == '\n' || i == len-1){
            if(i == len-1){
                res[p] = '\0';  // to delete last 
            }
            buff = &buff[i+1];
            res[p+1] = '\0';        
            return res; 
        }else{
            res[p] = buff[i]; 
        }
        p++;
    }

    free(buff);
    free(res);
    
    return NULL;
}