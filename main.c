#include "./main.h"

// node *head = NULL;
// node *current = NULL;

//find a link with given nid

int main() {
	node * head = NULL;
	readBackUp(&head);
	// insertFirst(5, &head);
	// insertEnd(21, &head);
	// insertEnd(3, &head);
	// insertEnd(1, &head);
	// removeNodes(&head, 1,5);
	// addBlockByNid(5,"NTS3",&head);
	// addBlockByNid(3,"123457",&head);
	// addBlockByNid(3,"31",&head);
	// addBlockByNid(3,"1578",&head);
	char ** blocks = malloc(2*sizeof(char*));
	blocks[0] = malloc(BIDSIZE);
	blocks[1] = malloc(BIDSIZE);
	blocks[0] = "check";
	blocks[1] = "check2";
	node* currentNode = findANode(5, head);
	addBlockstoNode(&head, currentNode, 2, blocks);
	// addBidToNodes(&head, "nts", 2, news); 
	// __deleteBidFromNode("31", 6, &head);
	deleteBidFromAllNodes("nts", &head);
	// delete(5, &head);
	int listing = 1;
	mySync(&head);
	printNodeList(head, listing);
	// quit(head);
  return 0;
}