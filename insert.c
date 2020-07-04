#include "./main.h"
//insert link at the first location
void insertFirst(int nid, node ** headPointer) {
	 node* head = *headPointer;
	 if (findANode(nid, head) != NULL){
		 printf("nid already exists");
		 return;
	 }
   //create a link
   node *newNode = (node*) malloc(sizeof(node));
	
   newNode->nid = nid;
   newNode->blockHead = NULL;
	
   //point it to old first node
   newNode->next = head;
	
   //point first to new first node
   *headPointer = newNode;
}

void insertEnd(int nid,node ** headPointer) {
	node* head = *headPointer;
   //create a link
	 if (findANode(nid, head) != NULL){
		 printf("nid exists");
		 return;
	 }	 
  node * newNode = (node*) malloc(sizeof(node));

  newNode->nid = nid;
  newNode->blockHead = NULL;
  newNode->next = NULL;

  node * p = head;
  while (p->next != NULL) {
      p = p->next;
  }

  p->next = newNode;
   
}