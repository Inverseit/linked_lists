#include "./main.h"

block* createBlock(char* bid){
	block* newBlock = malloc(sizeof(block));
	strcpy(newBlock->bid, bid);
	newBlock->next = NULL;
	return newBlock;
} 

int addBlockToNode(node* currentNode, block* currentBlock){
	block* p = currentNode->blockHead;
	if(p==NULL){
		currentNode->blockHead = currentBlock;
		return SUCCESS;
	}
	while(p->next!=NULL){
		p = p->next;
	}
	p->next = currentBlock;
	return SUCCESS;
}

int addBlockByNid(int nid, char * bid, node ** headPointer){
	node* head = *headPointer;
	node* current = findANode(nid, head);
	if(current == NULL){
		return NIDNOTFOUND;
	}
	block *currentBlock = createBlock(bid);
	return addBlockToNode(current, currentBlock);
}

void __deleteBidFromNode(char * bid, int nid, node** headPointer){
	int res = deleteBidFromNode("31", 3, headPointer);
	if(res!=SUCCESS){
		printf("\nerror:");
		if(res==NIDNOTFOUND) printf("Not found a block %s", bid);
	}
}

int deleteBidFromNode(char * bid, int nid, node** headPointer){
	node* head = *headPointer;
	node * currentNode = findANode(nid, head);
	block* currentBlock = currentNode->blockHead;
	block* prevBlock = currentBlock;
	int countCurrentBlock = 0;
	while(currentBlock != NULL){
		if (strcmp(&currentBlock->bid[0], bid)==0){
			if(countCurrentBlock == 0){
				block* nextBlock = currentBlock->next;
				block* tmp = currentBlock;
				currentNode->blockHead = nextBlock;
				free(tmp);
				return SUCCESS;
			}
			if(currentBlock->next == NULL){
				prevBlock->next = NULL;
				free(currentBlock);
				return SUCCESS;
			}
			// delete Middle
			block* nextBlock = currentBlock->next;
			block* tmp = currentBlock;
			prevBlock->next = nextBlock;
			free(tmp);
			return SUCCESS;
		}else{
			if(countCurrentBlock != 0){ 
				// Skip going next if it is the first iteration
				prevBlock = prevBlock->next;
			}
			currentBlock= currentBlock->next;
			countCurrentBlock++;
		}
	}
	// currentBlock==NULL
	return NIDNOTFOUND;
}