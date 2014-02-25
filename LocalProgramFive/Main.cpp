#include "Main.h"
#include <time.h>

using namespace std;

int main(const int argc, const char* argv[]) {

	srand(time(NULL));

	if (argc == 5)
	{
		FILE *output;
		output = fopen("packetsim.txt", "w");

		if (output != NULL) {
			vector<int> One(1, 0);
			vector<int> Route(1, 4);

			vector<int> Two(1, 1);
			vector<int> RouteTwo(1, 5);

			LinkListPacket *mOne = new LinkListPacket();
			mOne->insert(&Route, &One);
			mOne->insert(&RouteTwo, &Two);

			mOne->printList(output);

			mOne->getNextNode();

			mOne->printList(output);

			return 0;
		}
		else {
			printf("Output File couldn't be opened");
			return 1;
		}
	}
	else {
		printf("Incorrect Usage! Usage is ./prog5 #_of_sources #_of_recievers #_of_mules deimension");
		return 1;
	}
}
