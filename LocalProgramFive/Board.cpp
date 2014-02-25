#include "Board.h"

// Constructor
Board::Board(int length, int width, int numSources, int numMules, int numRecievers) {
	this->boardLayout = vector< vector<int> >(length, vector<int>(width));
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
void Board::initializeBoard() {
	for (size_t i = 0; i < this->length; i++) {
		for (size_t j = 0; j < this->width; j++)
		{
			(this->boardLayout.at(i)).at(j) = 0;
		}
	}
}

void Board::generateRandomNodePos(vector<Node> nodePos) {
	if (nodePos.size() != 0)
	{
		for (size_t i = 0; i < this->numSources; i++)
		{
			nodePos.at(i).setXCoord(0);
			nodePos.at(i).setYCoord(i);
		}
		for (size_t j = 0; j < this->numMules; j++)
		{

		}
		for (size_t k = 0; k < this->numRecievers; k++)
		{
			nodePos.at(k).setXCoord(length);
			nodePos.at(k).setYCoord(k);
		}
	}
}

void Board::setNodePos(vector<Node> nodeVector) {
	for (size_t i = 0; i < nodeVector.size(); i++)
	{
		int tempX = (nodeVector.at(i)).getXCoord();
		int tempY = (nodeVector.at(i)).getYCoord();
		(this->boardLayout.at(tempX)).at(tempY) = (nodeVector.at(i)).getId();
	}
}

void Board::printBoard(FILE *output) {
	for (size_t i = 0; i < this->boardLayout.size(); i++) {
		fprintf(output, "|");
		for (size_t j = 0; j < this->boardLayout.at(i).size(); j++)
		{
			if ((this->boardLayout.at(i)).at(j) == 0)
				fprintf(output, "   ");
			else
				fprintf(output, "%3d", (this->boardLayout.at(i)).at(j));
		}
	}
}