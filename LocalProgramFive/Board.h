#ifndef _BOARD_H
#define _BOARD_H

#include <vector>
#include "Node.h"

using namespace std;

class Board {
	public:
		// Constructor
		Board(int length = 0, int width = 0, vector<Node> nodeVector = *new vector<Node>(), int numSources = 0, int numMules = 0, int numRecievers = 0);

		// Accessors and Mutators
		vector< vector<int> > getBoardLayout();
		vector<Node> getNodeVector();
		int getLength();
		int getWidth();
		int getNumSources();
		int getNumMules();
		int getNumRecievers();
		int getNumPacketSent();
		int getNumPacketReceived();

		void setBoardLayout(vector< vector<int> > boardLayout);
		void setNodeVector(vector<Node> nodeVector);
		void setLength(int length);
		void setWidth(int width);
		void setNumSources(int numSources);
		void setNumMules(int numMules);
		void setNumRecievers(int numRecievers);
		void setNumPacketSent(int numPackets);
		void setNumReceived();

		// Object Functions
		void createNodeVector();
		void initializeBoard();
		void generateRandomNodePos();
		void setNodePos();
		void printRow(FILE *output);
		void printBoard(FILE *output);
		void printTable(FILE *output);
		void findSet(int id, int startTime, int sendNum, int sendSize, vector<int> sendRoute);
		void moveNodes();
		void totalNumPackets(string set);
		void runSimulation(FILE *output);

	private:
		vector< vector<int> > boardLayout;
		vector<Node> nodeVector;
		int length;
		int width;
		int numSources;
		int numMules;
		int numRecievers;
		int numPacketSent;
		int numPacketReceieved;
};

#endif
