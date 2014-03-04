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
	
	// All Node Use
	this->id = id;
	this->nodeType = "";
	this->xCoord = xCoord;
	this->yCoord = yCoord;
	this->direction = 0;
	this->currentPacket = NULL;
	this->currentPacketPQ = NULL;
	
	// Source Node Use
	this->sendRoute = *new vector<Node*>();
	this->startTime = 0;
	this->sendSize = 0;
	this->sendNum = 0;
	this->sendNumPQ = 0;
	
	// Mule Node Use
	this->queue = queue;
	this->pQSmall = *new LinkListPacket();
	this->pQMedium = *new LinkListPacket();
	this->pQLarge = *new LinkListPacket();
	
	// Receiver Node Use
	this->sumDelayTimeFCFS = 0;
	this->sumDelayTimePQ = 0;
	this->delayTimeFCFS = *new vector<double>(0);
	this->delayTimePQ = *new vector<double>(0);
	this->sumVarianceTimeFCFS = 0;
	this->sumVarianceTimePQ = 0;
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
/* Return the sum of the FCFS delay times of all packets sent by this Node */
double Node::getSumDelayTimeFCFS() const {
	return this->sumDelayTimeFCFS;
}
/* Return the sum of the PQ delay times of all packets sent by this Node */
double Node::getSumDelayTimePQ() const {
	return this->sumDelayTimePQ;
}
/* Return the sum FCFS variance of the delay time in this Node */
double Node::getSumVarianceTimeFCFS() const {
	return this->sumVarianceTimeFCFS;
}
/* Return the sum PQ variance of the delay time in this Node */
double Node::getSumVarianceTimePQ() const {
	return this->sumVarianceTimePQ;
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
/* Return this Node Priority small packet queue */
LinkListPacket Node::getPQSmall() {
	return this->pQSmall;
}
/* Return this Node Priority medium packet queue */
LinkListPacket Node::getPQMedium() {
	return this->pQMedium;
}
/* Return this Node Priority large packet queue */
LinkListPacket Node::getPQLarge() {
	return this->pQLarge;
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
	this->sendNumPQ = sendNum;
}
/* Set this Node total FCFS delay time of all packets to given double */
void Node::setSumDelayTimeFCFS(double sumDelayTime) {
	this->sumDelayTimeFCFS = sumDelayTime;
}
/* Set this Node total PQ delay time of all packets to given double */
void Node::setSumDelayTimePQ(double sumDelayTimePQ) {
	this->sumDelayTimePQ = sumDelayTimePQ;
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
/* Set this Node Priority small packet queue to given LinkListPacket */
void Node::setPQSmall(LinkListPacket pQSmall) {
	this->pQSmall = pQSmall;
}
/* Set this Node Priority medium packet queue to given LinkListPacket */
void Node::setPQMedium(LinkListPacket pQMedium) {
	this->pQMedium = pQMedium;
}
/* Set this Node Priority large packet queue to given LinkListPacket */
void Node::setPQLarge(LinkListPacket pQLarge) {
	this->pQLarge = pQLarge;
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
	// Move this Node one spot in its current direction
	nodeHop(length, width);

	// If new location is already occupied by another Node
	if (collisionCheck(nodeVector))
	{
		// Move this Node one more in its current direction
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
	
	// Directions of movement possible by Nodes
	enum directionWord{East, West, North, South};

	switch (this->direction)
	{
		case -1:      // Immovable Nodes like Sources/Receivers		
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
	
	// Iterate through the given vector of Nodes
	for (unsigned i = 0; i < nodeVector.size(); i++) {
		
		// Ignore Sources/Receivers as they are outside bounds and are immovable
		if (nodeVector.at(i).direction == -1)
		{
			continue;
		}

		// Skip if iterating Node is same as this Node
		else if (nodeVector.at(i).id == id)
		{
			continue;
		}
		else
		{
			// If iterating Node is located at the same coordinates as this Node 
			if (nodeVector.at(i).xCoord == xCoord && nodeVector.at(i).yCoord == yCoord)
			{
				// Return true to signal collision
				return true;
			}
		}
	}

	// No collision detected
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
	
	// If this is a Source Node and the TIME is greater than the start time and needs to send more Packets
	if (nodeType == "S" && TIME >= startTime && sendNum > 0)
	{
		// If not transmitting Packets
		if (currentPacket == NULL)
		{
			// Generate new Packet
			currentPacket = new Packet(&sendRoute, TIME, sendSize, 1, NULL);
		} 
		// If transmission of Packet is completed trigger new Packet generation and insertion of completed Packet to the first Mule queue
		else if (TIME == currentPacket->getPacketTimes().at(0) + currentPacket->getPacketSize())
		{
			// Add transmitted Packet to the first Mule Node queue in its route
			double arrivalTime = TIME + propogationTime(*(currentPacket->getPacketRoute().at(1)));
			currentPacket->modifyPacketTimes(arrivalTime);
			currentPacket->getPacketRoute().at(1)->queue.insert(currentPacket);

			// Decrement number of Packets to be sent and generate new Packet
			sendNum--;
			currentPacket = new Packet(&sendRoute, TIME, sendSize, 1, NULL);
		}
	}
	// If this Node is a Mule Node
	else if (nodeType == "M")
	{
		// If not transmitting Packet
		if (currentPacket == NULL)
		{
			// Get next Packet in Queue
			currentPacket = queue.getNextNode();
		}

		// If Packet is done transmitting trigger getting next Packet in Queue and insert the transmitted Packet to the next Node in its route
		else if (TIME >= currentPacket->getPacketTimes().at(currentPacket->getCurrentNode()) + currentPacket->getPacketSize() - 1)
		{
			// Increment Node index in Packets route
			currentPacket->setCurrentNode(1 + currentPacket->getCurrentNode());
			// Calculate arrival time at the next Node
			double arrivalTime = TIME + propogationTime(*(currentPacket->getPacketRoute().at(currentPacket->getCurrentNode())));
			// Add calculated arrival time at the currentNode index in the Packets time vector
			currentPacket->modifyPacketTimes(arrivalTime);
			// Add the Packet to the next Node queue
			currentPacket->getPacketRoute().at(currentPacket->getCurrentNode())->queue.insert(currentPacket);

			// Get the next Packet in this Node queue
			currentPacket = queue.getNextNode();
		}
		// If still transmitting Packet increment the arrival time of all Packets in this Node queue
		else
		{
			queue.incrementWaitTime(TIME);
		}
	}
	// If this Node is a Receiver
	else if (nodeType == "R")
	{
		// Iterate through all received Packets in this Node queue
		while (!queue.isEmpty())
		{
			// Get first Node in this Node queue
			currentPacket = queue.getNextNode();

			// If Packet is not empty
			if (currentPacket != NULL)
			{
				// Print info about received Packet 
				fprintf(output, "| %3d: %4.2f | ", currentPacket->getPacketRoute().at(0)->getId(), currentPacket->getPacketTimes().at(0));
				for (unsigned i = 1; i < currentPacket->getPacketTimes().size()-1; i++)
				{
					fprintf(output, "%3d: %4.2f | ", currentPacket->getPacketRoute().at(i)->getId(), currentPacket->getPacketTimes().at(i));
				}
				fprintf(output, "%3d: %4.2f |\n", currentPacket->getPacketRoute().at(currentPacket->getPacketRoute().size() - 1)->getId(), currentPacket->getPacketTimes().at(currentPacket->getPacketTimes().size() - 1));
				
				// Calculate Delay Time and add it to the sum delay time for later calculation of mean
				double delay = currentPacket->getPacketTimes().at(currentPacket->getPacketTimes().size() - 1) - currentPacket->getPacketTimes().at(0);
				sendNum++;
				sumDelayTimeFCFS += delay;

				// Add delay time to a vector of times to later calculate variance
				delayTimeFCFS.push_back(delay);
				numPacketReceieved++;

				delete currentPacket;
			}
		}
	}
}

/*
 * Sai Kiran Vadlamudi  C05
 * Run a Priority Queue simulation on this Node
 * 
 * Parameters:
 *	TIME: current time in the simulation
 *	numPacketRecieved: total number of packets received in the simulation
 *	output: pointer to the output file
 *
 *	Return:
 *	 void
 */
void Node::beginSimulationPQ(int TIME, int& numPacketReceivedPQ, vector<Node> nodeVector, FILE *output) {
	
	// If this Node is a Source and current TIME is greater or equal to starting time of this Node
	if (nodeType == "S" && TIME >= startTime && sendNumPQ > 0)
	{
		// If not transmitting a Packet
		if (currentPacketPQ == NULL)
		{
			// Generate new Packet
			currentPacketPQ = new Packet(&sendRoute, TIME, sendSize, 1, NULL);
		}
		// If Packet transmission is completed trigger new Packet generation and insertion of Packet into first Mule queue
		else if (TIME == currentPacketPQ->getPacketTimes().at(0) + currentPacketPQ->getPacketSize())
		{
			// Calculate arrival time of the completed Packet at the next Node
			double arrivalTime = TIME + propogationTime(*(currentPacketPQ->getPacketRoute().at(1)));
			currentPacketPQ->modifyPacketTimes(arrivalTime);
			
			// Add the completed Packet to either the small, medium or large queue based on the size of the Packet
			if (currentPacketPQ->getPacketSize() == 1)
				currentPacketPQ->getPacketRoute().at(1)->pQSmall.insert(currentPacketPQ);
			else if (currentPacketPQ->getPacketSize() == 2)
				currentPacketPQ->getPacketRoute().at(1)->pQMedium.insert(currentPacketPQ);
			else
				currentPacketPQ->getPacketRoute().at(1)->pQLarge.insert(currentPacketPQ);
			
			// Decrement number of Packets this Node needs to send
			sendNumPQ--;
			// Generate new Packet
			currentPacketPQ = new Packet(&sendRoute, TIME, sendSize, 1, NULL);
		}
	}
	// If this Node is a Mule
	else if (nodeType == "M")
	{
		// If not transmitting Packet
		if (currentPacketPQ == NULL) {
			// If queue not empty get the first Packet of the small Packet queue
			if (!pQSmall.isEmpty())
				currentPacketPQ = pQSmall.getNextNode();
			// If small queue is empty get the first Packet of the medium Packet queue
			else if (!pQMedium.isEmpty())
				currentPacketPQ = pQMedium.getNextNode();
			// If small and medium queues are empty get the first Packet of the large Packet queue
			else if (!pQLarge.isEmpty())
				currentPacketPQ = pQLarge.getNextNode();
		}
		// If Packet is transmitted trigger generation of new Packet and add transmitted Packet to next Mule
		else if (TIME >= currentPacketPQ->getPacketTimes().at(currentPacketPQ->getCurrentNode()) + currentPacketPQ->getPacketSize() - 1) {
			// Increment the index of the Node currently processing in the route
			currentPacketPQ->setCurrentNode(1 + currentPacketPQ->getCurrentNode());

			// Calculate and add the arrival time at the next Node
			double arrivalTime = TIME + propogationTime(*(currentPacketPQ->getPacketRoute().at(currentPacketPQ->getCurrentNode())));
			currentPacketPQ->modifyPacketTimes(arrivalTime);
			
			// If next Node in route is a Receiver add to large queue to minimize the number of queues to loop through at the receiver
			if (currentPacketPQ->getPacketRoute().at(currentPacketPQ->getCurrentNode())->getNodeType() == "R") {
				currentPacketPQ->getPacketRoute().at(currentPacketPQ->getCurrentNode())->pQLarge.insert(currentPacketPQ);
			}
			// Add the Packet to the next Node in its proper queue
			else {
				if (currentPacketPQ->getPacketSize() == 1)
					currentPacketPQ->getPacketRoute().at(currentPacketPQ->getCurrentNode())->pQSmall.insert(currentPacketPQ);
				else if (currentPacketPQ->getPacketSize() == 2)
					currentPacketPQ->getPacketRoute().at(currentPacketPQ->getCurrentNode())->pQMedium.insert(currentPacketPQ);
				else if (currentPacketPQ->getPacketSize() == 3)
					currentPacketPQ->getPacketRoute().at(currentPacketPQ->getCurrentNode())->pQLarge.insert(currentPacketPQ);
			}

			// Get the next Packet prioritized by size smallest first
			if (!pQSmall.isEmpty())
				currentPacketPQ = pQSmall.getNextNode();
			else if (!pQMedium.isEmpty())
				currentPacketPQ = pQMedium.getNextNode();
			else if (!pQLarge.isEmpty())
				currentPacketPQ = pQLarge.getNextNode();
			// All queues are empty
			else
				currentPacketPQ = NULL;
		}
		// Increment the arrival time at this Node of all the Packets in the three queues
		else {
			pQSmall.incrementWaitTime(TIME);
			pQMedium.incrementWaitTime(TIME);
			pQLarge.incrementWaitTime(TIME);
		}
	}
	// If this Node is a Receiver
	else if (nodeType == "R")
	{
		// Print results of all the packets received and remove them from simulation
		while (!pQLarge.isEmpty()) 
		{
			currentPacketPQ = pQLarge.getNextNode();

			if (currentPacketPQ != NULL)
			{
				fprintf(output, "| %3d: %4.2f | ", currentPacketPQ->getPacketRoute().at(0)->getId(), currentPacketPQ->getPacketTimes().at(0));
				for (unsigned i = 1; i < currentPacketPQ->getPacketTimes().size() - 1; i++)
				{
					fprintf(output, "%3d: %4.2f | ", currentPacketPQ->getPacketRoute().at(i)->getId(), currentPacketPQ->getPacketTimes().at(i));
				}
				fprintf(output, "%3d: %4.2f |\n", currentPacketPQ->getPacketRoute().at(currentPacketPQ->getPacketRoute().size() - 1)->getId(), currentPacketPQ->getPacketTimes().at(currentPacketPQ->getPacketTimes().size() - 1));

				// Calculate delay and add to running sum to calculate mean at a later time
				double delay = currentPacketPQ->getPacketTimes().at(currentPacketPQ->getPacketTimes().size() - 1) - currentPacketPQ->getPacketTimes().at(0);
				sendNumPQ++;
				sumDelayTimePQ += delay;

				// Add delay to the vector of times to later calculate variance
				delayTimePQ.push_back(delay);
				numPacketReceivedPQ++;

				delete currentPacketPQ;
			}
		}
	}
}


/*
 * Jordan Feeley  C05
 * Calculate the variance of the FCFS delay time for this Node
 * 
 * Parameters:
 *	None
 *	
 * Return:
 *	double
 */
void Node::calculateVarianceFCFS() {
	if (sendNum != 0)
	{
		double mean = sumDelayTimeFCFS / sendNum;

		for (unsigned i = 0; i < delayTimeFCFS.size(); i++)
		{
			sumVarianceTimeFCFS += pow((delayTimeFCFS.at(i) - mean), 2);
		}
	}
}

/*
 * Jordan Feeley  C05
 * Calculate the variance of the PQ delay time for this Node
 *
 * Parameters:
 *	None
 *
 * Return:
 *	double
 */
void Node::calculateVariancePQ() {
	if (sendNumPQ != 0)
	{
		double mean = sumDelayTimePQ / sendNumPQ;

		for (unsigned i = 0; i < delayTimePQ.size(); i++)
		{
			sumVarianceTimePQ += pow((delayTimePQ.at(i) - mean), 2);
		}
	}
}

