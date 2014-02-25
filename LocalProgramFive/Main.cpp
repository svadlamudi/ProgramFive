#include "Main.h"

using namespace std;

int main() {

	FILE *output;
	output = fopen("packetsim.txt", "w");

	vector<int> One(1, 0);
	vector<int> Route(1, 4);
	
	vector<int> Two(1, 1);
	vector<int> RouteTwo(1, 5);

	LinkListPacket *mOne = new LinkListPacket();
	mOne->insert(&Route, &One);
	mOne->insert(&RouteTwo, &Two);

	mOne->printList(output);

	printf("\n");

	mOne->getNextNode();

	mOne->printList(output);
}