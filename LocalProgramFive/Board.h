#ifndef _BOARD_H
#define _BOARD_H

#include <vector>
#include "Node.h"

using namespace std;

class Board {
	public:
		// Constructor
		Board(int length = 0, int width = 0, int numSources = 0, int numMules = 0, int numRecievers = 0);

		// Accessors and Mutators
		vector< vector<int> > getBoardLayout();
		int getLength();
		int getWidth();
		int getNumSources();
		int getNumMules();
		int getNumRecievers();

		void setBoardLayout(vector< vector<int> > boardLayout);
		void setLength(int length);
		void setWidth(int width);
		void setNumSources(int numSources);
		void setNumMules(int numMules);
		void setNumRecievers(int numRecievers);

		// Object Functions
		void initializeBoard();
		void generateRandomNodePos(vector<Node> nodePos);
		void setNodePos(vector<Node> nodeVector);
		void printBoard(FILE *output);

	private:
		vector< vector<int> > boardLayout;
		int length;
		int width;
		int numSources;
		int numMules;
		int numRecievers;
};

#endif
