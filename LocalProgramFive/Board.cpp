#include "Board.h"
#include <iostream>

using namespace std;

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
	this->boardLayout =  vector< vector<int> >(length, vector<int>(width));
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

	// Calculate total number of Nodes
	int totalNumNodes = numSources + numMules + numRecievers;
	// Create a new Vector to hold the Nodes
	vector<Node> tempVector = *new vector<Node>(totalNumNodes + 1);

	// Iterate through the Vector and assign Node ids
	for (unsigned i = 1; i < tempVector.size(); i++)
	{
		tempVector.at(i) = *new Node(i);
	}

	// Set new vector to this Board nodeVector
	nodeVector = tempVector;
}

/*
 * Jordan Feeley  C05
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
	
	// Iterate through all the nodes in this Board
	for (unsigned i = 1; i < nodeVector.size(); i++) {
		
		// If Node is a source
		if (i <= (unsigned)numSources)
		{
			// Assign properties to the source
			nodeVector.at(i).setNodeType("S");
			nodeVector.at(i).setDirection(-1);

			int tempXCoord = 0;
			int tempYCoord = rand() % (this->length - 1);

			for (int j = 1; j < numSources+1; j++)
			{
				while (tempXCoord == nodeVector.at(j).getXCoord() && tempYCoord == nodeVector.at(j).getYCoord())
				{
					tempXCoord = 0;
					tempYCoord = rand() % (this->length - 1);
				}
			}

			nodeVector.at(i).setXCoord(tempXCoord);
			nodeVector.at(i).setYCoord(tempYCoord);

		}

		// If Node is a mule
		else if (i >(unsigned)numSources && i <= (unsigned)(numMules + numSources))
		{
			// Generate random x and y
			int tempXCoord = (rand() % (this->width - 3)) + 1;
			int tempYCoord = rand() % (this->length - 1);

			// Check if a Node is placed already at that location
			for (unsigned j = 1; j < nodeVector.size(); j++)
			{
				while (tempXCoord == nodeVector.at(j).getXCoord() && tempYCoord == nodeVector.at(j).getYCoord())
				{
					tempXCoord = (rand() % ((this->width) - 3)) + 1;
					tempYCoord = rand() % (this->length - 1);
				}
			}

			// Assign properties to the mule
			nodeVector.at(i).setNodeType("M");
			nodeVector.at(i).setXCoord(tempXCoord);
			nodeVector.at(i).setYCoord(tempYCoord);
			nodeVector.at(i).setDirection(rand() % 3);
		}

		// If Node is a receiver
		else if (i > (unsigned)numMules && i <= (unsigned)(numSources + numMules + numRecievers))
		{
			// Assign properties to the receiver
			nodeVector.at(i).setNodeType("R");
			nodeVector.at(i).setDirection(-1);

			int tempXCoord = width - 1;
			int tempYCoord = rand() % (this->length - 1);

			for (unsigned j = numSources + numMules + numRecievers; j < nodeVector.size(); j++)
			{
				while (tempXCoord == nodeVector.at(j).getXCoord() && tempYCoord == nodeVector.at(j).getYCoord())
				{
					tempXCoord = width-1;
					tempYCoord = rand() % (this->length - 1);
				}
			}

			nodeVector.at(i).setXCoord(tempXCoord);
			nodeVector.at(i).setYCoord(tempYCoord);
		}
	}
}

/*
 * Jordan Feeley  C05
 * Set the positions of the Nodes on the board
 * 
 * Parameters:
 *	None
 *	
 * Return:
 *	void
 */
void Board::setNodePos() {
	
	// Iterate through the nodes on this Board
	for (unsigned i = 1; i < nodeVector.size(); i++)
	{
		// Draw the Node at this location
		int tempX = (nodeVector.at(i)).getXCoord();
		int tempY = (nodeVector.at(i)).getYCoord();
		(this->boardLayout.at(tempY)).at(tempX) = (nodeVector.at(i)).getId();
	}
}

/*
 * Jordan Feeley  C05
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
 * Jordan Feeley  C05
 * Print this Board
 * 
 * Parameters:
 *	output: pointer to the output file
 *	
 * Return:
 *	void
 */
void Board::printBoard(FILE *output, int TIME) {
	
	// Print column labels
	fprintf(output, "\nTime: %d\n", TIME);
	for (int k = 0; k < width; k++){
		fprintf(output, "%3d", k);
	}
	fprintf(output, "\n");
	
	// Print row separator
	printRow(output);
	
	// Iterate through this Board vector
	for (unsigned i = 0; i < this->boardLayout.size(); i++) {

		// Print the column separator
		fprintf(output, "|");

		for (unsigned j = 0; j < this->boardLayout.at(i).size(); j++)
		{
			// If first position in the row print source node
			if (j == (unsigned) 0) {
				
				// If no source at this location
				if ((this->boardLayout.at(i)).at(j) == 0)
					fprintf(output, "   |");
				else
					fprintf(output, "%3d|", (this->boardLayout.at(i)).at(j));
			}

			// If last position in the row print receiver node
			else if (j == (unsigned)width - 1){
				
				// If no receiver at this location
				if ((this->boardLayout.at(i)).at(j) == 0)
					fprintf(output, "|   ");
				else
					fprintf(output, "|%3d", (this->boardLayout.at(i)).at(j));
			}

			// If no mule at this location
			else if ((this->boardLayout.at(i)).at(j) == 0)
				fprintf(output, "   ");
			else
				fprintf(output, "%3d", (this->boardLayout.at(i)).at(j));
		}
		// Print column number
		fprintf(output, "| %3d\n", i);
	}
	// Print ending row separator
	printRow(output);
	fprintf(output, "\n");
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
	
	// Assign the given properties to the Node with the given ID
	nodeVector.at(id).setStartTime(startTime);
	nodeVector.at(id).setSendNum(sendNum);
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
	
	// Move all nodes in this Board one spot in their direction
	for (unsigned i = 1; i < nodeVector.size(); i++)
	{
		nodeVector.at(i).moveNode(nodeVector, length, width);
	}
}

/*
 * Jordan Feeley  C05
 * Calculate the total number of packets to be sent and received
 * 
 * Parameters:
 *	set: "S" for total sending packets and "R" for total received packets
 *	
 * Return:
 *	void
 */
void Board::totalNumPackets(string set, int& numPacketSent, int& numPacketReceieved) {
	// temp counter variable for counting number of packets sent or received
	int tempCounter = 0;

	// Calculate number of packets to be sent in the simulation
	if (set == "S")
	{
		for (int i = 1; i <= numSources; i++)
		{
			tempCounter += nodeVector.at(i).getSendNum();
		}
		numPacketSent = tempCounter;
	} 
	
	// Calculate number of packets received in the simulation
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
 *	output: pointer to the output log file
 *	type: "FCFS" or "PQ"
 *	
 * Return:
 *	void
 */
void Board::runSimulation(FILE *outputFCFS, FILE *outputPQ) {
	
	// Simulation variables
	int TIME = 0;
	int numPacketSent = 0, numPacketReceieved = 0, numPacketReceievedPQ = 0;
	totalNumPackets("S", numPacketSent, numPacketReceieved);
	cout << endl;

	// Run simulation while the number of packets received is lower than the number of packets sent
	while (numPacketReceieved < numPacketSent || numPacketReceievedPQ < numPacketSent)
	{
		// Iterate through the Nodes in this Board
		for (unsigned i = 1; i < nodeVector.size(); i++)
		{
			// Run FCFS on this Node
			nodeVector.at(i).beginSimulation(TIME, numPacketReceieved, nodeVector, outputFCFS);
			// Run PQ on this Node
			nodeVector.at(i).beginSimulationPQ(TIME, numPacketReceievedPQ, nodeVector, outputPQ);
		}

		// Move nodes every ten sims
		if (TIME > 0 && TIME % 10 == 0)
		{
			moveNodes();
			initializeBoard();
			setNodePos();
			printBoard(outputFCFS, TIME);
			printBoard(outputPQ, TIME);
			cout << "Completed: " << ceil(((double)(numPacketReceieved + numPacketReceievedPQ)) / (2 * numPacketSent) * 100) << "%\r" << flush;
		}

		// Increment time in simulation
		TIME++;
	}
	cout << "Simulation Completed.\nResults logged to manetSimFCFS.txt and manetSimPQ.txt.\n" << endl;
	// Print results for this simulation
	printResultsFCFS(TIME, numPacketReceieved, outputFCFS);
	printResultsPQ(TIME, numPacketReceieved, outputPQ);
}

/*
 * Sai Kiran Vadlamudi  C05
 * Print the FCFS results of the simulation
 * 
 * Parameters:
 *	None
 *
 * Return:
 *	void
 */
void Board::printResultsFCFS(int TIME, int numPacketReceieved, FILE *output) {
	
	// Temp. variables
	double totalDelayTimeFCFS = 0, totalVarianceTimeFCFS = 0;
	
	fprintf(output, "\n\n-------------------------------------------- Simulation Results Below --------------------------------------------------\n\n");
	printBoard(output, TIME);
	fprintf(output, "\n");
	for (unsigned i = numSources + numMules + 1; i < nodeVector.size(); i++)
	{
		nodeVector.at(i).calculateVarianceFCFS();
		double recieverMean = (nodeVector.at(i).getSendNum() != 0 ? nodeVector.at(i).getSumDelayTimeFCFS() / nodeVector.at(i).getSendNum() : 0.00);
		double recieverVariance = (nodeVector.at(i).getSendNum() != 0 ? nodeVector.at(i).getSumVarianceTimeFCFS() / nodeVector.at(i).getSendNum() : 0.00);
		fprintf(output, "| Receiver ID: %3d | Sum Delay Time: %7.0f | Packets Received: %4d | Mean Delay: %4.2f | Variance Delay: %4.2f |\n", nodeVector.at(i).getId(), nodeVector.at(i).getSumDelayTimeFCFS(), nodeVector.at(i).getSendNum(), recieverMean, recieverVariance);
		totalVarianceTimeFCFS += (nodeVector.at(i).getSumVarianceTimeFCFS());
		totalDelayTimeFCFS += (nodeVector.at(i).getSumDelayTimeFCFS());
	}
	fprintf(output, "\nOverall Mean Delay Time: %4.2f\n", totalDelayTimeFCFS / numPacketReceieved);
	fprintf(output, "Overall Variance Delay Time: %4.2f\n", totalVarianceTimeFCFS / numPacketReceieved);
	fprintf(output, "Final Simulation Time: %d\n", TIME);
	fprintf(output, "Total # of Packets Processed: %d\n", numPacketReceieved);
}

/*
* Sai Kiran Vadlamudi  C05
* Print the PQ results of the simulation
*
* Parameters:
*	None
*
* Return:
*	void
*/
void Board::printResultsPQ(int TIME, int numPacketReceieved, FILE *output) {

	// Temp variables
	double totalDelayTimePQ = 0, totalVarianceTimePQ = 0;

	fprintf(output, "\n\n-------------------------------------------- Simulation Results Below --------------------------------------------------\n\n");
	printBoard(output, TIME);
	fprintf(output, "\n");
	for (unsigned i = numSources + numMules + 1; i < nodeVector.size(); i++)
	{
		nodeVector.at(i).calculateVariancePQ();
		double recieverMean = (nodeVector.at(i).getSendNum() != 0 ? nodeVector.at(i).getSumDelayTimePQ() / nodeVector.at(i).getSendNum() : 0.00);
		double recieverVariance = (nodeVector.at(i).getSendNum() != 0 ? nodeVector.at(i).getSumVarianceTimePQ() / nodeVector.at(i).getSendNum() : 0.00);
		fprintf(output, "| Receiver ID: %3d | Sum Delay Time: %7.0f | Packets Received: %4d | Mean Delay: %4.2f | Variance Delay: %4.2f |\n", nodeVector.at(i).getId(), nodeVector.at(i).getSumDelayTimePQ(), nodeVector.at(i).getSendNum(), recieverMean, recieverVariance);
		totalVarianceTimePQ += (nodeVector.at(i).getSumVarianceTimePQ());
		totalDelayTimePQ += (nodeVector.at(i).getSumDelayTimePQ());
	}
	fprintf(output, "\nOverall Mean Delay Time: %4.2f\n", totalDelayTimePQ / numPacketReceieved);
	fprintf(output, "Overall Variance Delay Time: %4.2f\n", totalVarianceTimePQ / numPacketReceieved);
	fprintf(output, "Final Simulation Time: %d\n", TIME);
	fprintf(output, "Total # of Packets Processed: %d\n", numPacketReceieved);
}
