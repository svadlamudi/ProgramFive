#include "Packet.h"
#include <math.h>

// Constructors

/*
 * Jordan Feeley  C05
 * Create and return a pointer to the new Packet object
 * 
 * Parameters:
 *	packetRoute: vector of Node pointers to indicate this Packet route
 *	creationTime: time of this Packet creation
 *	packetSize: size of this Packet
 *	currentNode: currently waiting Node index in the packetRoute
 *	next: pointer to the next packet for linked list creation
 *	
 * Return:
 *	Packet*
 *
 */
Packet::Packet(vector<Node *> *packetRoute, int creationTime, int packetSize, int currentNode, Packet *next) {
	this->packetRoute = *packetRoute;
	this->packetTimes = *new vector<double>(packetRoute->size());
	this->packetTimes.at(0) = creationTime;
	this->packetSize = packetSize;
	this->currentNode = currentNode;
	this->next = next;
}

// Accessors and Mutators

/* Return this Packet route as a vector of Node* */
vector<Node *> Packet::getPacketRoute() const {
	return this->packetRoute;
}
/* Return this Packet arrival times at nodes as a vector of double */
vector<double> Packet::getPacketTimes() const {
	return this->packetTimes;
}
/* Return this Packet size */
int Packet::getPacketSize() const {
	return this->packetSize;
}
/* Return this Packet current index in the Node* vector */
int Packet::getCurrentNode() const {
	return this->currentNode;
}
/* Return a double pointer to next Packet */
Packet** Packet::getNext() {
	return &(this->next);
}

/* Set this Packet route as the given vector of Node* */
void Packet::setPacketRoute(vector<Node *> packetRoute) {
	this->packetRoute = packetRoute;
}
/* Set this Packet times as the given vector of double */
void Packet::setPacketTimes(vector<double> packetTimes) {
	this->packetTimes = packetTimes;
}
/* Set this Packet size as the given int */
void Packet::setPacketSize(int packetSize) {
	this->packetSize = packetSize;
}
/* Set this Packet current index in this packetRoute to the given int */
void Packet::setCurrentNode(int currentNode) {
	this->currentNode = currentNode;
}
/* Set this Packet next to the given pointer */
void Packet::setNext(Packet *next) {
	this->next = next;
}

// Object Functions

/*
 * Jordan Feeley  C05
 * Modify the time at the currentNode in the packetTimes to given time
 * 
 * Parameters:
 *	arrivalTime: the new arrival time
 *	
 * Return:
 *	void
 */
void Packet::modifyPacketTimes(double arrivalTime) {
	this->packetTimes[currentNode] = arrivalTime;
}
