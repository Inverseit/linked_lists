#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define EMPTYHEAD -1
#define NIDNOTFOUND -2
#define SUCCESS 0
#define BIDSIZE 20

typedef struct t_block {
   char bid[BIDSIZE];
   struct t_block *next;
} block;


typedef struct t_node {
   int nid;
   struct t_node *next;
   block * blockHead;
} node;


// Node Manupilations

void insertFirst(int nid, node ** headPointer);
void insertEnd(int nid,node ** headPointer);
bool isEmptyNode(node * head);
int lengthOfNodes(node * head);
node* findANode(int nid, node* head);
int delete(int nid, node ** headPointer);
void __delete(int nid, node ** headPointer);

// Block Manupilations

block* createBlock(char* bid);

int addBlockByNid(int nid, char * bid, node ** headPointer);
int addBlockToNode(node* currentNode, block* currentBlock);

int deleteBidFromNode(char * bid, int nid, node** headPointer);
void __deleteBidFromNode(char * bid, int nid, node** headPointer);


// Utils

void printNodeList(node * head);
void writeBackUp(node* head);
void quit(node* head);
