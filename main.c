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

int removeNodes(node ** headPointer,int number, ...){
	int nid;
  va_list vl;
  va_start(vl,number);
  for (int i=0;i<number;i++)
  {
		nid = va_arg(vl,int);
		__delete(nid, headPointer);
  }
  va_end(vl);
	return SUCCESS;
}

int addBidToNodes(node ** headPointer,char* bid, int number,...){
	printf("started running");
	int nid;
  va_list vl;
  va_start(vl,number);
  for (int i=0;i<number;i++)
  {
		nid = va_arg(vl,int);
		printf("inserting to a nid: %d \n", nid);
		addBlockByNid(nid,bid,headPointer);
		printf("Inserted to a nid: %d \n", nid);
  }
  va_end(vl);
	return SUCCESS;
}


int main() {
	node * head = NULL;
	insertFirst(5, &head);
	insertEnd(21, &head);
	insertEnd(3, &head);
	insertEnd(1, &head);
	removeNodes(&head, 1,5);
	addBlockByNid(3,"NTS3",&head);
	addBlockByNid(3,"123457",&head);
	addBlockByNid(3,"31",&head);
	addBlockByNid(3,"1578",&head);
	addBidToNodes(&head, "nts", 3, 21,1); 
	__deleteBidFromNode("31", 3, &head);
	delete(5, &head);
	printNodeList(head);
	quit(head);
  return 0;
}