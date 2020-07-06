#include "./main.h"
void readBackUp(node ** headPointer, int* syncPointer){
		int s = 0;
		int fd = open(BACKUPFILE, O_RDONLY);
    if (fd!=-1){
			// BACKUP EXISTS
			char *str = NULL;
			int currentNid = 0;
			int numberOfNodes = 0;
			while((str = readline(fd)) != NULL){
				// printf("%s\n", str);
				if(strncmp(str, "node ", 5) == 0){
					currentNid = atoi(&str[5]);
					numberOfNodes++;
					if(numberOfNodes==1){
						insertFirst(currentNid, headPointer);
					}else{
						insertEnd(currentNid, headPointer);
					}
				}else{
					if(strncmp(str, "block ", 6) == 0){
						char* bid = &str[6];
						addBlockByNid(currentNid, bid, headPointer,syncPointer);
						// printf("Create block: %s\n", &str[6]);
					}else{
						if(strncmp(str, "sync ", 5) == 0){
							char* type = &str[5];
							if(type[0] == '0'){
							 	s = 0; 
							}else{
								s = 1;
							}
							// printf("Create block: %s\n", &str[6]);
						}else{
							
						}
					}
				}
      	free(str);
			}
			*syncPointer = s;
			close(fd);
			return;
    }
    return;
}