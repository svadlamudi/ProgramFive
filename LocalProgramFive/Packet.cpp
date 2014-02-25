#include "Packet.h"


// Constructor
Packet::Packet(vector<int> *packetRoute, vector<int> *packetTimes, int currentNode, Packet *next) {
	this->packetRoute = *packetRoute;
	this->packetTimes = *packetTimes;
	this->currentNode = currentNode;
	this->next = next;
}

// Accessors and Mutators
vector<int> Packet::getPacketRoute() {
	return this->packetRoute;
}
vector<int> Packet::getPacketTimes() {
	return this->packetTimes;
}
int Packet::getCurrentNode() {
	return this->currentNode;
}
Packet** Packet::getNext() {
	return &(this->next);
}

void Packet::setPacketRoute(vector<int> packetRoute) {
	this->packetRoute = packetRoute;
}
void Packet::setPacketTimes(vector<int> packetTimes) {
	this->packetTimes = packetTimes;
}
void Packet::setCurrentNode(int currentNode) {
	this->currentNode = currentNode;
}
void Packet::setNext(Packet *next) {
	this->next = next;
}