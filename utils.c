#include "./main.h"
//display the list
void printNodeList(node * head, int listing) {
   node *ptr = head;
	
   //start from the beginning
   while(ptr != NULL) {
      printf("%d:",ptr->nid);
			if (listing){
				block* bptr = ptr->blockHead;
				while(bptr !=NULL){
					printf(" %s",&bptr->bid[0]);
					bptr = bptr->next;
					if (bptr != NULL) {
						printf(",");
					}
				}
			}
      ptr = ptr->next;
			if (ptr != NULL) {
				printf("\n");
			}
   }
	
   printf("\n");
}

//is list empty
bool isEmptyNode(node * head) {
   return head == NULL;
}

int lengthOfNodes(node * head) {
   int length = 0;
   node *current;
	
   for(current = head; current != NULL; current = current->next) {
      length++;
   }
	
   return length;
}

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