#include "Node.h"

// Constructors

/*
 * Sai Kiran Vadlamudi  C05
 * Create and return a pointer to a new Node object
 * 
 * Parameters:
 *	id: integer id of this Node
 *	xCoord: x-coordinate of this Node
 *	yCoord: y-coordinate of this Node
 *	queue: list of Packets empty for source and receiver nodes
 *	
 * Return:
 *	Node*
 */
Node::Node(int id, int xCoord, int yCoord, LinkListPacket queue) {
	this->id = id;
	this->nodeType = "";
	this->xCoord = xCoord;
	this->yCoord = yCoord;
	this->queue = queue;
	this->direction = 0;
	this->startTime = 0;
	this->sendSize = 0;
	this->sendNum = 0;
	this->sendNumBkp = 0;
	this->sumDelayTime = 0;
	this->sendRoute = *new vector<Node*>();
	this->currentPacket = NULL;
}

// Accessors and Mutators

/* Return this Node id */
int Node::getId() const {
	return this->id;
}
/* Return this Node type "S"/"M"/"R" */
string Node::getNodeType() const {
	return this->nodeType;
}
/* Return this Node x-coordinate */
int Node::getXCoord() const {
	return this->xCoord;
}
/* Return this Node y-coordinate */
int Node::getYCoord() const {
	return this->yCoord;
}
/* Return this Node direction */
int Node::getDirection() const {
	return this->direction;
}
/* Return this Node starting time of sending Packets */
int Node::getStartTime() const {
	return this->startTime;
}
/* Return this Node num of Packets to be sent */
int Node::getSendNum() const {
	return this->sendNum;
}
/* Return the sum of the delay times of all packets sent by this Node */
int Node::getSumDelayTime() const {
	return this->sumDelayTime;
}
/* Return this Node num of Packets to be sent */
int Node::getSendNumBkp() const {
	return this->sendNumBkp;
}
/* Return this Node size of Packets to be sent */
int Node::getSendSize() const {
	return this->sendSize;
}
/* Return this Node vector of Node* */
vector<Node*> Node::getSendRoute() const {
	return this->sendRoute;
}
/* Return this Node current processing Packet */
Packet* Node::getCurrentPacket() {
	return this->currentPacket;
}
/* Return this Node queue */
LinkListPacket Node::getQueue() {
	return this->queue;
}

/* Set this Node id to given int */
void Node::setId(int id) {
	this->id = id;
}
/* Set this Node type to given string "S"/"M"/"R" */
void Node::setNodeType(string nodeType) {
	if (nodeType == "S" || nodeType == "M" || nodeType == "R") {
		this->nodeType = nodeType;
	}
	else {
		printf("Invalid type of Node ID: %d", this->id);
		abort();
	}
}
/* Set this Node x-coordinate to given int */
void Node::setXCoord(int xCoord) {
	this->xCoord = xCoord;
}
/* Set this Node y-coordinate to given int */
void Node::setYCoord(int yCoord) {
	this->yCoord = yCoord;
}
/* Set this Node direction of movement to given int */
void Node::setDirection(int direction) {
	this->direction = direction;
}
/* Set this Node starting time to send Packets to given int */
void Node::setStartTime(int startTime) {
	if (startTime >= 0) {
		this->startTime = startTime;
	}
	else {
		printf("Invalid Start Time Source ID: %d", this->id);
		abort();
	}
}
/* Set this Node number of Packets to be sent to given int */
void Node::setSendNum(int sendNum) {
	this->sendNum = sendNum;
}
/* Set this Node total delay time of all packets to given int */
void Node::setSumDelayTime(int sumDelayTime) {
	this->sumDelayTime = sumDelayTime;
}
/* Set this Node number of Packets to be sent backup to given int */
void Node::setSendNumBkp(int sendNumBkp) {
	this->sendNumBkp = sendNumBkp;
}
/* Set this Node size of Packets to be sent to given int */
void Node::setSendSize(int sendSize) {
	if (sendSize > 0 && sendSize < 4) {
		this->sendSize = sendSize;
	}
	else {
		printf("Invalid Packet Size for Source ID: %d", this->id);
		abort();
	}	
}
/* Set this Node Packet route to given vector of Node* */
void Node::setSendRoute(vector<Node*> sendRoute) {
	this->sendRoute = sendRoute;
}
/* Set this Node current processing Packet to given Packet */
void Node::setCurrentPacket(Packet *currentPacket) {
	this->currentPacket = currentPacket;
}
/* Set this Node queue to given LinkListPacket */
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
	nodeHop(length, width);
	if (collisionCheck(nodeVector))
	{
		nodeHop(length, width);
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
void Node::beginSimulation(int TIME, int& numPacketReceieved, vector<Node> nodeVector, FILE *output) {
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
				fprintf(output, "| %d: %4.2f | ", currentPacket->getPacketRoute().at(0)->getId(), currentPacket->getPacketTimes().at(0));
				for (unsigned i = 1; i < currentPacket->getPacketTimes().size()-1; i++)
				{
					fprintf(output, "%d: %4.2f | ", currentPacket->getPacketRoute().at(i)->getId(), currentPacket->getPacketTimes().at(i));
				}
				fprintf(output, "%d: %4.2f |\n", currentPacket->getPacketRoute().at(currentPacket->getPacketRoute().size() - 1)->getId(), currentPacket->getPacketTimes().at(currentPacket->getPacketTimes().size() - 1));
				
				int delayTime = currentPacket->getPacketTimes().at(currentPacket->getPacketTimes().size() - 1) - currentPacket->getPacketTimes().at(0);
				sendNum++;
				sumDelayTime += delayTime;

				numPacketReceieved++;
				delete currentPacket;
			}
		}
	}
}
