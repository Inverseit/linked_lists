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
		// Adding first block
		currentNode->blockHead = currentBlock;
		return SUCCESS;
	}
	// Iterate to te last
	while(p->next!=NULL){
		p = p->next;
	}
	// Add to the last
	p->next = currentBlock;
	return SUCCESS;
}

int addBidByNode(node* currentNode, char * bid, node ** headPointer,int* syncPointer){
	node* head = *headPointer;
	node* current = currentNode;
	// Check if the block exists
	if(findBidInNode(current,bid)==NULL){
		// Adding new block
		block *currentBlock = createBlock(bid);
		*syncPointer = 0;
		return addBlockToNode(current, currentBlock);
	}
	// Block exists
	printf("$s block already exists");
	*syncPointer = 1;
	return BLOCKEXISTS;
}

int addBlockByNid(int nid, char * bid, node ** headPointer,int* syncPointer){
	node* head = *headPointer;
	node* current = findANode(nid, head);
	// Find node with nid
	if(current == NULL){
		*syncPointer = 1;
		return NIDNOTFOUND;
	}
	// Check if the block exists
	if(findBidInNode(current,bid)==NULL){
		// Adding new block
		block *currentBlock = createBlock(bid);
		*syncPointer = 0;
		return addBlockToNode(current, currentBlock);
	}
	// Block exists
	*syncPointer = 1;
	printf("$s block already exists");
	return BLOCKEXISTS;
}

void __deleteBidFromNode(char * bid, int nid, node** headPointer){
	// int res = 5;
	int res = deleteBidFromNode(bid, nid, headPointer);
	if(res!=SUCCESS){
		printf("\nerror:");
		if(res==NIDNOTFOUND) printf("Not found a node %d", nid);
		if(res==BLOCKNOTFOUND) printf("Not found a block %s", bid);
	}
}

block * findBidInNode(node * currentNode, char *bid){
	block* currentBlock = currentNode->blockHead;
	while(currentBlock != NULL){
		if (strcmp(&currentBlock->bid[0], bid)==0){
			return currentBlock;
		}
		currentBlock = currentBlock->next;
	}
	return NULL;
}


int deleteBidFromNode(char * bid, int nid, node** headPointer){
	node* head = *headPointer;
	node * currentNode = findANode(nid, head);
	if (currentNode == NULL){
		return NIDNOTFOUND;
	}
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
	return BLOCKNOTFOUND;
}

int addBlockstoNode(node ** headPointer,node * currentNode, int length, char ** bidArray, int* syncPointer){
	// delete all blocks
	for(int i = 0; i< length; i++){
		char *bid = &bidArray[i][0];
		addBidByNode(currentNode, bid, headPointer, syncPointer);
	}
	return SUCCESS;
}


void deleteBidFromAllNodes(char* bid, node** headPointer){
	node * p = *headPointer;
	if (p==NULL){
		return;
	}
	while( p != NULL){
		block* currentBlock = findBidInNode(p, bid);
		if( currentBlock != NULL){
			__deleteBidFromNode(bid, p->nid, headPointer);
		}
		p = p->next;
	}
}

void freeBlockArray(char ** blockArray, int length){
	for(int i=0; i<length;i++){
		free(blockArray[i]);
		// printf("BID:%s\n",blockArray[i]);
	}
	free(blockArray);
}

int removeBlocksFromAllNodes(node ** headPointer,int length,char** bidArray){
	char* bid;
  for (int i=0;i<length;i++)
  {
		bid = bidArray[i];
		deleteBidFromAllNodes(bid, headPointer);
  }

	freeBlockArray(bidArray, length);

	return SUCCESS;
}