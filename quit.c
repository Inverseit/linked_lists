#include "./main.h"
void writeBackUp(node* head, int*syncPointer){
	 FILE * fp;
	 fp = fopen (BACKUPFILE,"w");
   node *ptr = head;	
   //start from the beginning
	 fprintf(fp,"sync %d\n",*syncPointer);
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

void quit(node * head, int *syncPointer){
	writeBackUp(head,syncPointer);
	exit(0);
}