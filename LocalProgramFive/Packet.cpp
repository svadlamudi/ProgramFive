#include "Packet.h"


// Constructor
Packet::Packet(vector<int> *packetRoute, vector<int> *packetTimes, Packet *next) {
	this->packetRoute = *packetRoute;
	this->packetTimes = *packetTimes;
	this->next = next;
}

// Accessors and Mutators
vector<int> Packet::getPacketRoute() {
	return this->packetRoute;
}
vector<int> Packet::getPacketTimes() {
	return this->packetTimes;
}
Packet* Packet::getNext() {
	return this->next;
}

void Packet::setPacketRoute(vector<int> packetRoute) {
	this->packetRoute = packetRoute;
}
void Packet::setPacketTimes(vector<int> packetTimes) {
	this->packetTimes = packetTimes;
}
