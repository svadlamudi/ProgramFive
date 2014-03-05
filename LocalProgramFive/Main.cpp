// Importing libraries and declarations
#include "Main.h"
#include <time.h>

using namespace std;

/*
 * Sai Kiran Vadlamudi  C05
 * Jordan Feeley  C05
 *
 * Main
 * Driver function
 */
int main(const int argc, const char* argv[]) {

	// Seed for random number generator
	srand((unsigned)time(NULL));

	// Check for correct number of command line arguments
	if (argc == 6)
	{
		// Temp variables to store user input from file
		int id = 0, startTime = 0, sendNum = 0, sendSize = 0, routeSize = 0, routeId = 0;
		FILE *input, *outputFCFS, *outputPQ;
		
		// Open files
		outputFCFS = fopen("manetSimFCFS.txt", "w");
		outputPQ = fopen("manetSimPQ.txt", "w");
		input = fopen(argv[5], "r");

		if (outputFCFS != NULL && input != NULL) {
			
			// Print heading and output format
			fprintf(outputFCFS, "Name: Jordan Feeley        Section: C05\n");
			fprintf(outputFCFS, "Name: Sai Kiran Vadlamudi  Section: C05\n\n");
			fprintf(outputFCFS, "| Source: Arrival Time | All Mules: All Arrival Times | Receiver: Arrival Time\n\n");
			fprintf(outputPQ, "Name: Jordan Feeley        Section: C05\n");
			fprintf(outputPQ, "Name: Sai Kiran Vadlamudi  Section: C05\n\n");
			fprintf(outputPQ, "| Source: Arrival Time | All Mules: All Arrival Times | Receiver: Arrival Time\n\n");
			
			// Set-up, Randomize, and print board for first time
			Board manetMap = *new Board(atoi(argv[4]), atoi(argv[4]) + 2, *new vector<Node>(), atoi(argv[1]), atoi(argv[3]), atoi(argv[2]));
			manetMap.createNodeVector();
			manetMap.initializeBoard();
			manetMap.generateRandomNodePos();
			manetMap.setNodePos();
			manetMap.printBoard(outputFCFS);
			manetMap.printBoard(outputPQ);

			// Read in the source node info
			for (int i = 0; i < atoi(argv[1]); i++)
			{
				// Read in the first five properties of the source node in the current line 
				fscanf(input, "%d %d %d %d %d", &id, &startTime, &sendNum, &sendSize, &routeSize);
				
				// Create a vector of ids of mule nodes along the route
				vector<int> temp = *new vector<int>();
				for (int j = 0; j < routeSize; j++)
				{
					fscanf(input, "%d", &routeId);
					temp.push_back(routeId);
				}

				// Add the input properties to the source node matching the given id
				manetMap.findSet(id, startTime, sendNum, sendSize, temp);
			}

			// Run simulation
			manetMap.runSimulation(outputFCFS, outputPQ);

			// Close files
			fclose(input);
			fclose(outputFCFS);
			fclose(outputPQ);

			return 0;
		}
		else {
			// Output file corrupted
			if (outputFCFS == NULL)
				printf("Output File couldn't be opened\n\n");
			// Input file corrupted
			else
				printf("Input File couldn't be opened\n\n");

			return 1;
		}
	}
	else {
		printf("Incorrect Usage! Usage is ./prog5 #_of_sources #_of_recievers #_of_mules dimension input_file\n\n");
		return 1;
	}
}

