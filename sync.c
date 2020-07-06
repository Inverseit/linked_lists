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
	char ** blockArray;
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
				if(count > 0){
					blockArray = realloc(blockArray,(count+1)*sizeof(char*));
				}else{
					blockArray = malloc(sizeof(char*));
				}
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

void freeBlockArray(char ** blockArray, int length){
	for(int i=0; i<length;i++){
		free(blockArray[i]);
	}
	free(blockArray);
}

void mySync(node ** headPointer){
	int length = 0;
	char ** blockArray = getAllBlocks(headPointer, &length);
	for(int i=0; i<length;i++){
		char* bid  =&blockArray[i][0];
		deleteBidFromAllNodes(bid, headPointer); 
		// I know it is not the most efficient way to do so
	}
	node * p = *headPointer;
	while(p!=NULL){
		// printf("int nid:%d", p->nid);
		addBlockstoNode(headPointer,p, length, blockArray);
		p = p->next;
	}

	freeBlockArray(blockArray, length);
}