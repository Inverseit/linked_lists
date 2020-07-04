#include "./main.h"
void writeBackUp(node* head){
	 FILE * fp;
	 fp = fopen ("backup.txt","w");
   node *ptr = head;	
   //start from the beginning
   while(ptr != NULL) {
		 	node * tmpNode = ptr;
      fprintf(fp,"node %d\n",ptr->nid);
			block* bptr = ptr->blockHead;
			while(bptr !=NULL){
				fprintf(fp,"block %s\n",&bptr->bid[0]);
				block* tmpBlock = bptr; 
				bptr = bptr->next;
				free(tmpBlock);
			}
      ptr = ptr->next;
			free(tmpNode);
   }
}

void quit(node * head){
	writeBackUp(head);
	exit(0);
}