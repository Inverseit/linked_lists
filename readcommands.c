#include "main.h"
char** readCommands(char* input, int* commandsSize) {
		// printf("nts");
	 int len = strlen(input);
	 char* inputString = malloc(len);
	 strcpy(inputString, input);
	 int count = 0;
   char ** commands = malloc(sizeof(char*));
   // Extract the first token
	 char * token = malloc(sizeof(char)*ONECOMMAND );
	//  printf("nts");
   token = strtok(inputString, " ");
   // loop through the string to extract all other tokens
   while( token != NULL ) {
			commands = realloc(commands, (count+1)*sizeof(char*));
			commands[count] = malloc(ONECOMMAND*sizeof(char));
      // printf( " %s\n", token ); //printing each token
			strcpy(commands[count], token);
			count++;
      token = strtok(NULL, " ");
   }

	 for(int i =0; i< count; i++){
		 printf("command: %s\n", commands[i]);
	 }
	 free(inputString);
	 *commandsSize = count;
   return commands;
}

bool isEqStr(char* a, char*b){
	return strcmp(a, b) ==0;
}

int execute(int argc, char** argv,node **headPointer){
	// add node _nid_ 
	if(argc == 3){
		if(isEqStr(argv[0],"add") && isEqStr(argv[1],"node")){
			int nid = atoi(argv[2]); // add check if int
			insertEnd(nid, headPointer);
		}
	}
	// rm node _nid_...
	if(isEqStr(argv[0],"rm") && isEqStr(argv[1],"node")){
		if(isEqStr(argv[2],"*")){
			deleteAllNodes(headPointer);
		}else{
			for (int i =2; i < argc; i++){
				int nid = atoi(argv[2]); // add check if int
				__delete(nid, headPointer);
			}
		}
	}	

	freeBlockArray(argv, argc);
	return 0;
}