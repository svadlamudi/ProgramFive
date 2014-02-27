#include "Packet.h"
#include <math.h>

// Constructor
Packet::Packet(vector<Node *> *packetRoute, int creationTime, int packetSize, int currentNode, Packet *next) {
	this->packetRoute = *packetRoute;
	this->packetTimes = *new vector<double>(packetRoute->size());
	this->packetTimes.at(0) = creationTime;
	this->packetSize = packetSize;
	this->currentNode = currentNode;
	this->next = next;
}

// Accessors and Mutators
vector<Node *> Packet::getPacketRoute() {
	return this->packetRoute;
}
vector<double> Packet::getPacketTimes() {
	return this->packetTimes;
}
int Packet::getPacketSize() {
	return this->packetSize;
}
int Packet::getCurrentNode() {
	return this->currentNode;
}
Packet** Packet::getNext() {
	return &(this->next);
}

void Packet::setPacketRoute(vector<Node *> packetRoute) {
	this->packetRoute = packetRoute;
}
void Packet::setPacketTimes(vector<double> packetTimes) {
	this->packetTimes = packetTimes;
}
void Packet::setPacketSize(int packetSize) {
	this->packetSize = packetSize;
}
void Packet::setCurrentNode(int currentNode) {
	this->currentNode = currentNode;
}
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