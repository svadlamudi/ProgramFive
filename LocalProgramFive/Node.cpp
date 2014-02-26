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

/*
 * Sai Kiran Vadlamudi  C05
 * Calculate the propagation time from this node to receiving node
 * 
 * Parameters:
 *	recieveNode: node that the packet is being sent to
 *	
 * Return:
 *	double
 */
double Node::propogationTime(Node recieveNode) {

	double xLen = abs(recieveNode.xCoord - xCoord);
	double yLen = abs(recieveNode.yCoord - yCoord);

	double sqrtLen = sqrt(pow(xLen, 2.0) + pow(yLen, 2.0));

	return ceil(log(sqrtLen) / log(2));
}

/*
 * Sai Kiran Vadlamudi  C05
 * Hop this node
 * 
 * Parameters:
 *	nodeVector: vector of the source, mule, and receiver nodes
 *	length: length of the board
 *	width: width of the board
 *	
 * Return:
 *	void
 */
void Node::moveNode(vector<Node> nodeVector, int length, int width) {
	this->nodeHop(length, width);
	if (collisionCheck(nodeVector))
	{
		this->nodeHop(length, width);
	}
}

/*
 * Sai Kiran Vadlamudi  C05
 * Move this node one spot in its current direction checking for edges
 * 
 * Parameters:
 *	length: length of the board
 *	width: width of the board
 * 
 * Return:
 *	void
 */
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

/*
 * Sai Kiran Vadlamudi  C05
 * Check for collisions after the move (node bounce)
 * 
 * Parameters:
 *	nodeVector: vector of source, mule, and receiver nodes
 *	
 * Return:
 *	void
 */
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
