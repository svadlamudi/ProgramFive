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

		void setBoardLayout(vector< vector<int> > boardLayout);
		void setNodeVector(vector<Node> nodeVector);
		void setLength(int length);
		void setWidth(int width);
		void setNumSources(int numSources);
		void setNumMules(int numMules);
		void setNumRecievers(int numRecievers);

		// Object Functions
		void initializeBoard();
		void generateRandomNodePos();
		void setNodePos();
		void printBoard(FILE *output);
		void moveNodes();

	private:
		vector< vector<int> > boardLayout;
		vector<Node> nodeVector;
		int length;
		int width;
		int numSources;
		int numMules;
		int numRecievers;
};

#endif
