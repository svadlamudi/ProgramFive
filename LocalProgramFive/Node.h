#ifndef _NODE_H
#define _NODE_H

#include <cstdlib>

class Node {
	public:
		// Constructor
		Node(int id = -1, int xCoord = -1, int yCoord = -1, Node *next = NULL);

		// Accessors and Mutators
		int getId();
		int getXCoord();
		int getYCoord();
		Node * getNext();

		void setId(int id);
		void setXCoord(int xCoord);
		void setYCoord(int yCoord);
		void setNext(Node **next);

		// Object Functions

		
	private:
		int id;
		int xCoord;
		int yCoord;
		Node *next;
};

#endif
