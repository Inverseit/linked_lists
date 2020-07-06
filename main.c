#include "./main.h"

// node *head = NULL;
// node *current = NULL;

//find a link with given nid

int main() {
	int sync = 0;
	node * head = NULL;
	// readBackUp(&head,&sync);
	insertFirst(5, &head);
	// insertEnd(21, &head);
	// insertEnd(3, &head);
	// insertEnd(1, &head);
	// removeNodes(&head, 1,5);
	// addBlockByNid(5,"NTS3",&head);
	// addBlockByNid(3,"123457",&head);
	// addBlockByNid(3,"31",&head);
	// addBlockByNid(3,"1578",&head);
	// char ** blocks = malloc(2*sizeof(char*));
	// blocks[0] = malloc(BIDSIZE);
	// blocks[1] = malloc(BIDSIZE);
	// blocks[0] = "check";
	// blocks[1] = "check2";
	// node* currentNode = findANode(5, head);	
	// addBlockstoNode(&head, currentNode, 2, blocks, &sync);
	// char ** blockArray = malloc(1*sizeof(char*));
	// blockArray[0] = malloc(BIDSIZE);
  // strcpy(blockArray[0], "32");
	// removeBlocksFromAllNodes(&head, 1, blockArray);
	// addBidToNodes(&head, "nts", 2, news); 
	// __deleteBidFromNode("31", 6, &head);
	// deleteBidFromAllNodes("nts", &head);
	// delete(5, &head);
	int listing = 1;
	// mySync(&head, &sync);
	// printNodeList(head, listing);
	// quit(head, &sync);
	int size = 0;
	char * in = "add node 7";
	char** commandsArray = readCommands(in, &size);
	execute(size, commandsArray, &head);
	printNodeList(head, listing);
  return 0;
}