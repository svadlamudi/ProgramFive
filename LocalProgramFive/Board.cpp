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
	if (nodeVector.size() != 0)
	{
		for (int i = 0; i < this->numSources; i++)
		{
			nodeVector.at(i).setXCoord(0);
			nodeVector.at(i).setYCoord(i);
			nodeVector.at(i).setDirection(-1);
		}
		for (int j = numSources - 1; j < this->numMules; j++)
		{
			int tempXCoord = (rand() % (this->width - 2)) + 1;
			int tempYCoord = rand() % (this->length - 1);
			for (unsigned k = 0; k < nodeVector.size(); k++)
			{
				while (tempXCoord == nodeVector.at(k).getXCoord() && tempYCoord == nodeVector.at(k).getYCoord())
				{
					tempXCoord = (rand() % (this->width - 2)) + 1;
					tempYCoord = rand() % (this->length - 1);
				}
			}
			nodeVector.at(j).setXCoord(tempXCoord);
			nodeVector.at(j).setYCoord(tempYCoord);
			nodeVector.at(j).setDirection(rand() % 3);
		}
		for (int k = numMules - 1; k < numRecievers; k++)
		{
			nodeVector.at(k).setXCoord(this->length);
			nodeVector.at(k).setYCoord(k);
			nodeVector.at(k).setDirection(-1);
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
	for (unsigned i = 0; i < nodeVector.size(); i++)
	{
		int tempX = (nodeVector.at(i)).getXCoord();
		int tempY = (nodeVector.at(i)).getYCoord();
		(this->boardLayout.at(tempX)).at(tempY) = (nodeVector.at(i)).getId();
	}
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
	for (unsigned i = 0; i < this->boardLayout.size(); i++) {
		fprintf(output, "|");
		for (unsigned j = 0; j < this->boardLayout.at(i).size(); j++)
		{
			if ((this->boardLayout.at(i)).at(j) == 0)
				fprintf(output, "   ");
			else
				fprintf(output, "%3d", (this->boardLayout.at(i)).at(j));
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
	for (unsigned i = 0; i < nodeVector.size(); i++)
	{
		nodeVector.at(i).moveNode(nodeVector, length, width);
	}
}