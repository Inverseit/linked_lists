#include "./main.h"
//display the list
void printNodeList(node * head) {
   node *ptr = head;
   printf("\nCurrent nodes:{\n");
	
   //start from the beginning
   while(ptr != NULL) {
      printf("%d:",ptr->nid);
			block* bptr = ptr->blockHead;
			while(bptr !=NULL){
				printf("[%s]",&bptr->bid[0]);
				bptr = bptr->next;
				if (bptr != NULL) {
					printf(",");
				}
			}
      ptr = ptr->next;
			if (ptr != NULL) {
				printf("\n");
			}
   }
	
   printf("\n}");
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