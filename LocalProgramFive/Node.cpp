#include "Node.h"

// Constructor
Node::Node(int id, int xCoord, int yCoord, LinkListPacket queue) {
	this->id = id;
	this->nodeType = "";
	this->xCoord = xCoord;
	this->yCoord = yCoord;
	this->queue = queue;
	this->direction = 0;
	this->startTime = 0;
	this->sendSize = 0;
	this->sendRoute = *new vector<Node*>();
	this->currentPacket = NULL;
	this->sendNum = 0;
}

// Accessors and Mutators
int Node::getId() {
	return this->id;
}
string Node::getNodeType() {
	return this->nodeType;
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
int Node::getStartTime() {
	return this->startTime;
}
int Node::getSendNum() {
	return this->sendNum;
}
int Node::getSendSize() {
	return this->sendSize;
}
vector<Node*> Node::getSendRoute() {
	return this->sendRoute;
}
Packet* Node::getCurrentPacket() {
	return this->currentPacket;
}
LinkListPacket Node::getQueue() {
	return this->queue;
}

void Node::setId(int id) {
	this->id = id;
}
void Node::setNodeType(string nodeType) {
	this->nodeType = nodeType;
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
void Node::setStartTime(int startTime) {
	this->startTime = startTime;
}
void Node::setSendNum(int sendNum) {
	this->sendNum = sendNum;
}
void Node::setSendSize(int sendSize) {
	this->sendSize = sendSize;
}
void Node::setSendRoute(vector<Node*> sendRoute) {
	this->sendRoute = sendRoute;
}
void Node::setCurrentPacket(Packet *currentPacket) {
	this->currentPacket = currentPacket;
}
void Node::setQueue(LinkListPacket queue) {
	this->queue = queue;
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
 * Jordan Feeley  C05
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
	nodeHop(length, width);
	if (collisionCheck(nodeVector))
	{
		nodeHop(length, width);
	}
}

/*
 * Jordan Feeley  C05
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
 * Jordan Feeley  C05
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

/*
 * Sai Kiran Vadlamudi  C05
 * Run simulation on this node
 * 
 * Parameters:
 *	TIME: current time in the simulation
 *	numPacketRecieved: total number of packets received in the simulation
 *	output: pointer to the output file
 *	
 *	Return:
 *	 void
 */
void Node::beginSimulation(int TIME, int& numPacketReceieved, FILE *output) {
	if (nodeType == "S" && TIME >= startTime && sendNum > 0)
	{
		if (currentPacket == NULL)
		{
			currentPacket = new Packet(&sendRoute, TIME, sendSize, 1, NULL);
		} 
		else if (TIME == currentPacket->getPacketTimes().at(0) + currentPacket->getPacketSize())
		{
			double arrivalTime = TIME + propogationTime(*(currentPacket->getPacketRoute().at(1)));
			currentPacket->modifyPacketTimes(arrivalTime);
			currentPacket->getPacketRoute().at(1)->queue.insert(currentPacket);

			sendNum--;
			currentPacket = new Packet(&sendRoute, TIME, sendSize, 1, NULL);
		}
	}
	else if (nodeType == "M")
	{
		if (currentPacket == NULL)
		{
			currentPacket = queue.getNextNode();
		}
		else if (TIME >= currentPacket->getPacketTimes().at(currentPacket->getCurrentNode()) + currentPacket->getPacketSize() - 1)
		{
			currentPacket->setCurrentNode(1 + currentPacket->getCurrentNode());
			double arrivalTime = TIME + propogationTime(*(currentPacket->getPacketRoute().at(currentPacket->getCurrentNode())));
			currentPacket->modifyPacketTimes(arrivalTime);
			currentPacket->getPacketRoute().at(currentPacket->getCurrentNode())->queue.insert(currentPacket);

			currentPacket = queue.getNextNode();
		}
		else
		{
			queue.incrementWaitTime(TIME);
		}
	}
	else if (nodeType == "R")
	{
		while (!queue.isEmpty())
		{
			currentPacket = queue.getNextNode();

			if (currentPacket != NULL)
			{
				fprintf(output, "|%d|", currentPacket->getPacketRoute().at(0)->getId());
				for (unsigned i = 1; i < currentPacket->getPacketTimes().size()-1; i++)
				{
					fprintf(output, "%4.2f|", currentPacket->getPacketTimes().at(i));
				}
				fprintf(output, "%d|\n", currentPacket->getPacketRoute().at(currentPacket->getPacketRoute().size() - 1)->getId());
				numPacketReceieved++;
			}
		}
	}
}
