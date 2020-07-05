#include "./main.h"

// node *head = NULL;
// node *current = NULL;

//find a link with given nid
node* findANode(int nid, node* head) {
   //start from the first link
   node* current = head;

   //if list is empty
   if(isEmptyNode(head)) {
      return NULL;
   }

   //navigate through list
   while(current->nid != nid) {
	
      //if it is last node
      if(current->next == NULL) {
         return NULL;
      } else {
         //go to next link
         current = current->next;
      }
   }      
	
   //if data found, return the current Link
   return current;
}

int removeNodes(node ** headPointer,int length, int* nidArray){
	int nid;
  for (int i=0;i<length;i++){
		nid = nidArray[i];
		__delete(nid, headPointer);
  }
	return SUCCESS;
}

int addBidToNodes(node ** headPointer,char* bid, int length, int* nidArray){
	int nid;
  for (int i=0;i<length;i++)
  {
		nid = nidArray[i];
		addBlockByNid(nid, bid, headPointer);
  }

	return SUCCESS;
}


void deleteBidFromAllNodes(char* bid, node** headPointer){
	node * p = *headPointer;
	while( p==NULL && p->next != NULL){
		block* currentBlock = findBidInNode(p, bid);
		if( currentBlock != NULL){
			__deleteBidFromNode(bid, p->nid, headPointer);
		}
		p = p->next;
	}
}


int removeBlocks(node ** headPointer,int length,char** bidArray){
	char* bid;
  for (int i=0;i<length;i++)
  {
		bid = bidArray[i];
		deleteBidFromAllNodes(bid, headPointer);
  }

	return SUCCESS;
}


int main() {
	node * head = NULL;
	// readBackUp(&head);
	insertFirst(5, &head);
	// insertEnd(21, &head);
	// insertEnd(3, &head);
	insertEnd(1, &head);
	// removeNodes(&head, 1,5);
	addBlockByNid(5,"NTS3",&head);
	// addBlockByNid(3,"123457",&head);
	// addBlockByNid(3,"31",&head);
	// addBlockByNid(3,"1578",&head);
	int * news = malloc(2* sizeof(int));
	news[0] = 5;
	news[1] = 1;
	addBidToNodes(&head, "nts", 2, news); 
	// __deleteBidFromNode("31", 3, &head);
	// delete(5, &head);
	// int listing = 1;
	mySync(&head);
	// printNodeList(head, listing);
	quit(head);
  return 0;
}