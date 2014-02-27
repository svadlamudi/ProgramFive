#include "Board.h"

// Constructor
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
vector< vector<int> > Board::getBoardLayout() {
	return this->boardLayout;
}
vector<Node> Board::getNodeVector() {
	return this->nodeVector;
}
int Board::getNumSources() {
	return this->numSources;
}
int Board::getNumMules() {
	return this->numMules;
}
int Board::getNumRecievers() {
	return this->numRecievers;
}

void Board::setBoardLayout(vector< vector<int> > boardLayout) {
	this->boardLayout = boardLayout;
}
void Board::setNodeVector(vector<Node> nodeVector) {
	this->nodeVector = nodeVector;
}
void Board::setNumSources(int numSources) {
	this->numSources = numSources;
}
void Board::setNumMules(int numMules) {
	this->numMules = numMules;
}
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
 * Initialize the board with all 0s
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
 * Set the positions of the nodes on the board
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
 * Print the board
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
 * Print the table of node positions
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

void Board::findSet(int id, int startTime, int sendNum, int sendSize, vector<int> sendRoute) {
	for (unsigned i = 1; i < nodeVector.size(); i++)
	{
		if (nodeVector.at(i).getId() == id)
		{
			nodeVector.at(i).setStartTime(startTime);
			nodeVector.at(i).setSendNum(sendNum);
			nodeVector.at(i).setSendSize(sendSize);
			vector<Node*> temp = *new vector<Node *>(sendRoute.size());
			for (unsigned j = 0; j < sendRoute.size(); j++)
			{
				for (unsigned k = 0; k < nodeVector.size(); k++)
				{
					if (sendRoute.at(j) == nodeVector.at(k).getId())
					{
						temp.at(j) = &nodeVector.at(k);
						break;
					}
				}
			}
			nodeVector.at(i).setSendRoute(temp);
			break;
		} 
		else
		{
			continue;
		}
	}
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
	totalNumPackets("S", numPacketSent, numPacketReceieved);

	while (numPacketReceieved < numPacketSent)
	{
		for (unsigned i = 1; i < nodeVector.size(); i++)
		{
			nodeVector.at(i).beginSimulation(TIME, numPacketReceieved, output);
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
}