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


int main() {
	node * head = NULL;
	insertFirst(5, &head);
	insertEnd(21, &head);
	insertEnd(3, &head);
	__delete(5, &head);
	addBlockByNid(3,"NTS3",&head);
	addBlockByNid(3,"123",&head);
	addBlockByNid(3,"31",&head);
	addBlockByNid(3,"1578",&head);
	__deleteBidFromNode("31", 3, &head);
	// delete(5, &head);
	// printNodeList(head);
	quit(head);
  return 0;
}