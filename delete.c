#include "./main.h"

void __delete(int nid,node ** headPointer ){
		int res = delete(nid, headPointer);
	if(res!=SUCCESS){
		printf("\nerror:");
		if(res==EMPTYHEAD) printf("Emprty head");
		if(res==NIDNOTFOUND) printf("Not found node %d", nid);
	}
}

int delete(int nid,node ** headPointer ) {
	 node* head = *headPointer;
   //start from the first link
   node* current = head;
   node* previous = NULL;
	
   //if list is empty
   if(isEmptyNode(head)) {
      return EMPTYHEAD;
   }

   //navigate through list
   while(current->nid != nid) {

      //if it is last node
      if(current->next == NULL) {
         return NIDNOTFOUND;
      } else {
         //store reference to current link
         previous = current;
         //move to next link
         current = current->next;
      }
   }

   //found a match, update the link
   if(current == head) {
      //change first to point to next link
      node *tmp = head;
      head = head->next;
      free(tmp);
   } else {
      //bypass the current link
      previous->next = current->next;
			free(current);
   }    
	*headPointer = head;
	return SUCCESS;
}


int removeNodes(node ** headPointer,int length, int* nidArray){
	int nid;
  for (int i=0;i<length;i++){
		nid = nidArray[i];
		__delete(nid, headPointer);
  }
	free(nidArray);
	return SUCCESS;
}