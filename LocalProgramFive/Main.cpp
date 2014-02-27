#include "Main.h"
#include <time.h>

using namespace std;

int main(const int argc, const char* argv[]) {

	srand((unsigned)time(NULL));

	if (argc == 5)
	{
		int id = 0, startTime = 0, sendNum = 0, sendSize = 0, routeSize = 0, routeId = 0;
		FILE *output;
		FILE *input;
		output = fopen("packetsim.txt", "w");
		input = fopen("sourcenodelist.txt", "r");

		if (output != NULL && input != NULL) {
			// Set-up Board
			Board manetMap = *new Board(atoi(argv[4]), atoi(argv[4]) + 2, *new vector<Node>(), atoi(argv[1]), atoi(argv[3]), atoi(argv[2]));
			manetMap.createNodeVector();
			manetMap.initializeBoard();
			manetMap.generateRandomNodePos();
			manetMap.setNodePos();
			manetMap.printBoard(output);

			//for (int i = 0; i < atoi(argv[1]); i++)
			for (int i = 0; i < 1; i++)
			{
				fscanf(input, "%d %d %d %d %d", &id, &startTime, &sendNum, &sendSize, &routeSize);
				vector<int> temp = *new vector<int>();
				for (int j = 0; j < routeSize; j++)
				{
					fscanf(input, "%d", &routeId);
					temp.push_back(routeId);
				}
				manetMap.findSet(id, startTime, sendNum, sendSize, temp);
			}

			manetMap.totalNumPackets("S");
			manetMap.runSimulation(output);

			return 0;
		}
		else {
			
			if (output == NULL)
				printf("Output File couldn't be opened");
			else
				printf("Input File couldn't be opened");

			return 1;
		}
	}
	else {
		printf("Incorrect Usage! Usage is ./prog5 #_of_sources #_of_recievers #_of_mules dimension");
		return 1;
	}
}
