#include "Node.h"

// Constructor
Node::Node(int id, int xCoord, int yCoord, LinkListPacket queue, Node *next) {
	this->id = id;
	this->xCoord = xCoord;
	this->yCoord = yCoord;
	this->next = next;
}

// Accessors and Mutators
int Node::getId() {
	return this->id;
}
int Node::getXCoord() {
	return this->xCoord;
}
int Node::getYCoord() {
	return this->yCoord;
}
int Node::getDirection() {
	return this->direction;
}
Node * Node::getNext() {
	return this->next;
}

void Node::setId(int id) {
	this->id = id;
}
void Node::setXCoord(int xCoord) {
	this->xCoord = xCoord;
}
void Node::setYCoord(int yCoord) {
	this->yCoord = yCoord;
}
void Node::setDirection(int direction) {
	this->direction = direction;
}
void Node::setNext(Node **next) {
	this->next = *next;
}

// Object Functions
void Node::moveNode(vector<Node> nodeVector, int length, int width) {
	this->nodeHop(length, width);
	if (collisionCheck(nodeVector))
	{
		this->nodeHop(length, width);
	}
}

void Node::nodeHop(int length, int width) {
	
	enum directionWord{East, West, North, South};

	switch (direction)
	{
		case -1:
			break;
		case East:
			if (xCoord + 1 <= width - 2) {
				xCoord++;
			} 
			else {
				direction = West;
				xCoord--;
			}
			break;
		case West:
			if (xCoord - 1 >= 1) {
				xCoord--;
			} 
			else {
				direction = East;
				xCoord++;
			}
			break;
		case North:
			if (yCoord - 1 >= 0) {
				yCoord--;
			} 
			else {
				direction = South;
				yCoord++;
			}
			break;
		case South:
			if (yCoord + 1 < length) {
				yCoord++;
			} 
			else {
				direction = North;
				yCoord--;
			}
			break;			
		default:
			printf("Invalid Direction");
	}
}

bool Node::collisionCheck(vector<Node> nodeVector) {
	for (unsigned i = 0; i < nodeVector.size(); i++) {
		if (nodeVector.at(i).direction == -1)
		{
			continue;
		}
		else if (nodeVector.at(i).id == id)
		{
			continue;
		}
		else
		{
			if (nodeVector.at(i).xCoord == xCoord && nodeVector.at(i).yCoord == yCoord)
			{
				return true;
			}
		}
	}
	return false;
}
