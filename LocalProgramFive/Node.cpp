#include "Node.h"

// Constructor
Node::Node(int id, int xCoord, int yCoord, Node *next) {
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
void Node::setNext(Node **next) {
	this->next = *next;
}

// Object Functions