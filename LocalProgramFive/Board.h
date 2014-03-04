#ifndef _BOARD_H
#define _BOARD_H

// Importing libraries and declarations
#include <vector>
#include "Node.h"
#include <cstdio>

using namespace std;

class Board {
	public:
		// Constructor
		Board(int length = 0, int width = 0, vector<Node> nodeVector = *new vector<Node>(), int numSources = 0, int numMules = 0, int numRecievers = 0);

		// Accessors and Mutators
		vector< vector<int> > getBoardLayout() const;
		vector<Node> getNodeVector() const;
		int getLength() const;
		int getWidth() const;
		int getNumSources() const;
		int getNumMules() const;
		int getNumRecievers() const;

		void setBoardLayout(vector< vector<int> > boardLayout);
		void setNodeVector(vector<Node> nodeVector);
		void setLength(int length);
		void setWidth(int width);
		void setNumSources(int numSources);
		void setNumMules(int numMules);
		void setNumRecievers(int numRecievers);

		// Object Functions
		void createNodeVector();
		void initializeBoard();
		void generateRandomNodePos();
		void setNodePos();
		void printRow(FILE *output);
		void printBoard(FILE *output, int TIME = 0);
		void printTable(FILE *output);
		void findSet(int id, int startTime, int sendNum, int sendSize, vector<int> sendRoute);
		void moveNodes();
		void totalNumPackets(string set, int& numPacketSent, int& numPacketReceieved);
		void runSimulation(FILE *outputFCFS, FILE *outputPQ);
		void printResultsFCFS(int TIME, int numPacketReceieved, FILE *output);
		void printResultsPQ(int TIME, int numPacketReceieved, FILE *output);

	private:
		vector< vector<int> > boardLayout;   // Holds the positions of the Nodes to print out
		vector<Node> nodeVector;             // Holds the Nodes in this simulation
		int length;                          // Length of the board read in from command line arguments
		int width;							 // Width of the board read in from the command line arguments plus two to hold the sources and recievers
		int numSources;                      // # of Sources in this simulation read in from command line arguments
		int numMules;                        // # of Mules in this simulation read in from command line arguments
		int numRecievers;                    // # of Receivers in this simulation read in from command line arguments
};

#endif
