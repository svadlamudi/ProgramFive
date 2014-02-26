#ifndef _NODE_H
#define _NODE_H

#include <cstdlib>
#include <math.h>
#include "LinkListPacket.h"

class Node {
	public:
		// Constructor
		Node(int id = -1, int xCoord = -1, int yCoord = -1, LinkListPacket queue = *(new LinkListPacket()), Node *next = NULL);

		// Accessors and Mutators
		int getId();
		int getXCoord();
		int getYCoord();
		int getDirection();
		Node * getNext();

		void setId(int id);
		void setXCoord(int xCoord);
		void setYCoord(int yCoord);
		void setDirection(int direction);
		void setNext(Node **next);

		// Object Functions
		double propogationTime(Node recieveNode);
		void moveNode(vector<Node> nodeVector, int length, int width);
		void nodeHop(int length, int width);
		bool collisionCheck(vector<Node> nodeVector);
		
	private:
		int id;
		int xCoord;
		int yCoord;
		int direction;
		LinkListPacket queue;
		Node *next;
};

#endif
