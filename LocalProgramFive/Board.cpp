#include "Board.h"

// Constructors

/*
 * Sai Kiran Vadlamudi  C05
 * Constructor and return a pointer to new Board object
 * 
 * Parameters:
 *	length: length, height, of the board
 *	width: width of the board including the two columns of sources and receivers
 *	nodeVector: vector of source, mule, and receiver nodes
 *	numSources: number of sources in the simulation
 *	numMules: number of mules in the simulation
 *	numRecievers: number of receivers in the simulation
 *	
 * Return:
 *	Board*	
 */
Board::Board(int length, int width, vector<Node> nodeVector, int numSources, int numMules, int numRecievers) {
	this->boardLayout = vector< vector<int> >(length, vector<int>(width));
	this->nodeVector = nodeVector;
	this->length = length;
	this->width = width;
	this->numSources = numSources;
	this->numMules = numMules;
	this->numRecievers = numRecievers;
}

// Accessors and Mutators

/* Return the 2D vector of integers, node ids or 0 , of this Board */
vector< vector<int> > Board::getBoardLayout() const {
	return this->boardLayout;
}

/* Return the vector of nodes in this Board */
vector<Node> Board::getNodeVector() const {
	return this->nodeVector;
}

/* Return the number of sources in this Board */
int Board::getNumSources() const {
	return this->numSources;
}
/* Return the number of sources in this Board */
int Board::getNumMules() const {
	return this->numMules;
}
/* Return the number of receivers in this Board */
int Board::getNumRecievers() const{
	return this->numRecievers;
}

/* Set the 2D vector of integers of this Board to the given vector */
void Board::setBoardLayout(vector< vector<int> > boardLayout) {
	this->boardLayout = boardLayout;
}
/* Set the vector of nodes in this Board to the given vector */
void Board::setNodeVector(vector<Node> nodeVector) {
	this->nodeVector = nodeVector;
}
/* Set the numSources in this Board to the given integer */
void Board::setNumSources(int numSources) {
	this->numSources = numSources;
}
/* Set the numMules in this Board to the given integer */
void Board::setNumMules(int numMules) {
	this->numMules = numMules;
}
/* Set the numRecievers in this Board to the given integer */
void Board::setNumRecievers(int numRecievers) {
	this->numRecievers = numRecievers;
}

// Object Functions

/*
 * Sai Kiran Vadlamudi  C05
 * Create a node vector with the source, mule, and receiver nodes
 * 
 * Parameters:
 *	None
 *	
 * Return:
 *	void
 */
void Board::createNodeVector() {

	int totalNumNodes = numSources + numMules + numRecievers;
	vector<Node> tempVector = *new vector<Node>(totalNumNodes + 1);

	for (unsigned i = 1; i < tempVector.size(); i++)
	{
		tempVector.at(i) = *new Node(i);
	}

	nodeVector = tempVector;
}

/*
 * Sai Kiran Vadlamudi  C05
 * Initialize this board with all 0s
 * 
 * Parameters:
 *	None
 *	
 * Return:
 *	void
 */
void Board::initializeBoard() {
	for (int i = 0; i < this->length; i++) {
		for (int j = 0; j < this->width; j++)
		{
			(this->boardLayout.at(i)).at(j) = 0;
		}
	}
}

/*
 * Sai Kiran Vadlamudi  C05
 * Generate random positions and directions for the mules
 * 
 * Parameters:
 *	None
 *	
 * Return:
 *	void
 */
void Board::generateRandomNodePos() {
	for (unsigned i = 1; i < nodeVector.size(); i++) {
		if (i <= (unsigned)numSources)
		{
			nodeVector.at(i).setNodeType("S");
			nodeVector.at(i).setXCoord(0);
			nodeVector.at(i).setYCoord(i - 1);
			nodeVector.at(i).setDirection(-1);
		}
		else if (i >(unsigned)numSources && i <= (unsigned)(numMules + numSources))
		{
			int tempXCoord = (rand() % (this->width - 3)) + 1;
			int tempYCoord = rand() % (this->length - 1);
			for (unsigned j = 1; j < nodeVector.size(); j++)
			{
				while (tempXCoord == nodeVector.at(j).getXCoord() && tempYCoord == nodeVector.at(j).getYCoord())
				{
					tempXCoord = (rand() % ((this->width) - 3)) + 1;
					tempYCoord = rand() % (this->length - 1);
				}
			}
			nodeVector.at(i).setNodeType("M");
			nodeVector.at(i).setXCoord(tempXCoord);
			nodeVector.at(i).setYCoord(tempYCoord);
			nodeVector.at(i).setDirection(rand() % 3);
		}
		else if (i > (unsigned)numMules && i <= (unsigned)(numSources + numMules + numRecievers))
		{
			nodeVector.at(i).setNodeType("R");
			nodeVector.at(i).setXCoord(width-1);
			nodeVector.at(i).setYCoord(i - (numSources + numMules + 1));
			nodeVector.at(i).setDirection(-1);
		}
	}
}

/*
 * Sai Kiran Vadlamudi  C05
 * Set the positions of the Nodes on the board
 * 
 * Parameters:
 *	None
 *	
 * Return:
 *	void
 */
void Board::setNodePos() {
	for (unsigned i = 1; i < nodeVector.size(); i++)
	{
		int tempX = (nodeVector.at(i)).getXCoord();
		int tempY = (nodeVector.at(i)).getYCoord();
		(this->boardLayout.at(tempY)).at(tempX) = (nodeVector.at(i)).getId();
	}
}

/*
 * Sai Kiran Vadlamudi  C05
 * Prints a row of '-'
 * 
 * Parameters:
 *	None
 *	
 * Return:
 *	void
 */
void Board::printRow(FILE *output) {
	//fprintf(output, "+");
	for (unsigned i = 0; i < (unsigned)width * 3 + 4; i++)
	{
		//fprintf(output, "---+");
		fprintf(output, "-");
	}
	fprintf(output, "\n");
}

/*
 * Sai Kiran Vadlamudi  C05
 * Print this Board
 * 
 * Parameters:
 *	output: pointer to the output file
 *	
 * Return:
 *	void
 */
void Board::printBoard(FILE *output) {
	printRow(output);
	for (unsigned i = 0; i < this->boardLayout.size(); i++) {
		fprintf(output, "|");
		for (unsigned j = 0; j < this->boardLayout.at(i).size(); j++)
		{
			if (j == (unsigned) 0) {
				if ((this->boardLayout.at(i)).at(j) == 0)
					fprintf(output, "   |");
				else
					fprintf(output, "%3d|", (this->boardLayout.at(i)).at(j));
			}				
			else if (j == (unsigned) width-1)
				if ((this->boardLayout.at(i)).at(j) == 0)
					fprintf(output, "|   ");
				else
					fprintf(output, "|%3d", (this->boardLayout.at(i)).at(j));
			else if ((this->boardLayout.at(i)).at(j) == 0)
				fprintf(output, "   ");
			else
				fprintf(output, "%3d", (this->boardLayout.at(i)).at(j));
		}
		fprintf(output, "|\n");
		//printRow(output);
	}
	printRow(output);
	fprintf(output, "\n");
}

/*
 * Sai Kiran Vadlamudi  C05
 * Print the table of Node positions
 * 
 * Parameters:
 *	None
 *	
 * Return:
 *	void
 */
void Board::printTable(FILE *output) {
	for (size_t i = 1; i < nodeVector.size(); i++)
	{
		if (nodeVector.at(i).getNodeType() == "S")
		{
			if (i == 1)
			{
				fprintf(output, "Source Nodes: ");
			}
		}
		else if (nodeVector.at(i).getNodeType() == "M")
		{
			
		}
		else if (nodeVector.at(i).getNodeType() == "R")
		{
			
		}
	}
}

/*
 * Sai Kiran Vadlamudi  C05
 * Find the Node with the given id and set the given Node properties to that Node
 * 
 * Parameters:
 *	id: id of the Node to find
 *	startTime: time found Node starts sending Packets
 *	sendNum: number of Packets to send by found Node
 *	sendSize: size of Packets to send by found Node
 *	sendRoute: vector of integer id by which found Node sends Packets
 *	
 * Return:
 *	void
 */
void Board::findSet(int id, int startTime, int sendNum, int sendSize, vector<int> sendRoute) {
	nodeVector.at(id).setStartTime(startTime);
	nodeVector.at(id).setSendNum(sendNum);
	nodeVector.at(id).setSendNumBkp(sendNum);
	nodeVector.at(id).setSendSize(sendSize);
	vector<Node*> temp = *new vector<Node *>(sendRoute.size());
	for (unsigned i = 0; i < sendRoute.size(); i++)
	{
		temp.at(i) = &nodeVector.at(sendRoute.at(i));
	}
	nodeVector.at(id).setSendRoute(temp);
}

/*
 * Sai Kiran Vadlamudi  C05
 * Move all mule nodes in this board
 * 
 * Parameters:
 *	None
 *	
 * Return:
 *	void
 */
void Board::moveNodes() {
	for (unsigned i = 1; i < nodeVector.size(); i++)
	{
		nodeVector.at(i).moveNode(nodeVector, length, width);
	}
}

/*
 * Sai Kiran Vadlamudi  C05
 * Calculate the total number of packets to be sent and received
 * 
 * Parameters:
 *	set: "S" for total sending packets and "R" for total received packets
 *	
 * Return:
 *	void
 */
void Board::totalNumPackets(string set, int& numPacketSent, int& numPacketReceieved) {
	
	int tempCounter = 0;

	if (set == "S")
	{
		for (int i = 1; i <= numSources; i++)
		{
			tempCounter += nodeVector.at(i).getSendNum();
		}
		numPacketSent = tempCounter;
	} 
	else if (set == "R")
	{
		for (int i = (numSources + numMules); i <= (numSources + numMules + numRecievers); i++)
		{
			tempCounter += nodeVector.at(i).getSendNum();
		}
		numPacketReceieved = tempCounter;
	}
}

/*
 * Sai Kiran Vadlamudi  C05
 * Run the simulation on the nodes in this nodeVector
 * 
 * Parameters:
 *	None
 *	
 * Return:
 *	void
 */
void Board::runSimulation(FILE *output) {
	
	int TIME = 0;
	int numPacketSent = 0, numPacketReceieved = 0;
	double totalDelayTime = 0;
	totalNumPackets("S", numPacketSent, numPacketReceieved);

	while (numPacketReceieved < numPacketSent)
	{
		for (unsigned i = 1; i < nodeVector.size(); i++)
		{
			nodeVector.at(i).beginSimulation(TIME, numPacketReceieved, nodeVector, output);
		}
	
		if (TIME > 0 && TIME % 10 == 0)
		{
			moveNodes();
			initializeBoard();
			setNodePos();
			printBoard(output);
		}

		TIME++;
	}	

	fprintf(output, "\n\n-------------------------------------------- Simulation Results Below --------------------------------------------------\n\n");
	printBoard(output);
	fprintf(output, "\n");
	for (unsigned i = numSources + numMules + 1; i < nodeVector.size(); i++)
	{
		fprintf(output, "| Receiver ID: %3d | Sum Delay Time: %7.0d | Packets Received: %4d | Mean Delay: %4.2f |\n", nodeVector.at(i).getId(), nodeVector.at(i).getSumDelayTime(), nodeVector.at(i).getSendNum(), nodeVector.at(i).getSendNum() != 0 ? nodeVector.at(i).getSumDelayTime() / nodeVector.at(i).getSendNum() : 0.00);
		totalDelayTime += (nodeVector.at(i).getSumDelayTime());
	}
	fprintf(output, "\nOverall Mean Delay Time: %4.2f\n", totalDelayTime / numPacketReceieved);
	fprintf(output, "Final Simulation Time: %d\n", TIME);
	fprintf(output, "Total # of Packets Processed: %d\n", numPacketReceieved);
}
