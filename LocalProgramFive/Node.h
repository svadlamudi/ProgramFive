#ifndef _NODE_H
#define _NODE_H

#include <cstdlib>
#include "LinkListPacket.h"

class Node {
	public:
		// Constructor
		Node(int id = -1, int xCoord = -1, int yCoord = -1, LinkListPacket queue = *(new LinkListPacket()), Node *next = NULL);

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
		LinkListPacket queue;
		Node *next;
};

#endif
