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
	int nid;
  va_list vl;
  va_start(vl,number);
  for (int i=0;i<number;i++)
  {
		nid = va_arg(vl,int);
		addBlockByNid(nid,bid,headPointer);
  }
  va_end(vl);
	return SUCCESS;
}

void readBackUp(node ** headPointer){
		int fd = open(BACKUPFILE, O_RDONLY);
    if (fd!=-1){
			// BACKUP EXISTS
			char *str = NULL;
			int currentNid = 0;
			int numberOfNodes = 0;
			while((str = readline(fd)) != NULL){
				// printf("%s\n", str);
				if(strncmp(str, "node ", 5) == 0){
					currentNid = atoi(&str[5]);
					numberOfNodes++;
					if(numberOfNodes==1){
						insertFirst(currentNid, headPointer);
					}else{
						insertEnd(currentNid, headPointer);
					}
				}else{
					if(strncmp(str, "block ", 6) == 0){
						char* bid = &str[6];
						addBlockByNid(currentNid, bid, headPointer);
						// printf("Create block: %s\n", &str[6]);
					}else{
						printf("backup is corrupted");
					}
				}
      	free(str);
			}
			close(fd);
			return;
    }
    return;
}




int main() {
	node * head = NULL;
	readBackUp(&head);
	// insertFirst(5, &head);
	// insertEnd(21, &head);
	// insertEnd(3, &head);
	// insertEnd(1, &head);
	// removeNodes(&head, 1,5);
	// addBlockByNid(3,"NTS3",&head);
	// addBlockByNid(3,"123457",&head);
	// addBlockByNid(3,"31",&head);
	// addBlockByNid(3,"1578",&head);
	// addBidToNodes(&head, "nts", 2, 21,1); 
	// __deleteBidFromNode("31", 3, &head);
	// delete(5, &head);
	printNodeList(head);
	// quit(head);
  return 0;
}