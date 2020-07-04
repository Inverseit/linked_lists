#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define BACKUPFILE "backup.txt"
#define EMPTYHEAD -1
#define NIDNOTFOUND -2
#define SUCCESS 0
#define BIDSIZE 20
#define BLOCKEXISTS -3

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

block* findBidInNode(node * currentNode, char *bid);

int deleteBidFromNode(char * bid, int nid, node** headPointer);
void __deleteBidFromNode(char * bid, int nid, node** headPointer);


// Utils

void printNodeList(node * head);
void writeBackUp(node* head);
void quit(node* head);


char* readline(int fd);