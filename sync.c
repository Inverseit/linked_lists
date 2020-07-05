#include "./main.h"

int isBidInArray(char* bid, int length, char** blockArray){
	if(length == 0){
		return 0;
	}
	for(int i =0; i < length; i++){
		if(strcmp(bid, blockArray[i]) == 0){
			return 1;
		}
	}
	return 0;
}

char ** getAllBlocks(node ** headPonter, int* countP){
	char ** blockArray = malloc(1);
	int count =0;
	node* head = *headPonter;
	node* currentNode = head;
	while(currentNode!=NULL){
		block * currentBlock = currentNode->blockHead;
		// printf("working on node %d\n",currentNode->nid);
		while(currentBlock!=NULL){
			char* bid = currentBlock->bid;
			// printf("reading block: %s\n",bid);
			if(!isBidInArray(bid,count, blockArray)){
				// printf("\n%s is new to the array\n", bid);
				blockArray = realloc(blockArray,count+1);
				blockArray[count] = malloc(BIDSIZE);
				strcpy(&blockArray[count][0], bid);
				count = count+1;
			}
			currentBlock = currentBlock->next;
		}
		currentNode = currentNode->next;
	}
	*countP = count;
	return blockArray;
}

void mySync(node ** headPonter){
	int length = 0;
	char ** blockArray = getAllBlocks(headPonter, &length);
	for(int i=0; i<length;i++){
		printf("[%s]",&blockArray[i][0]);
	}
}