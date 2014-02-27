#ifndef _PACKET_H
#define _PACKET_H

#include <string>
#include <vector>

using namespace std;

class Node;

class Packet {
	public:
		// Constructors
		Packet(vector<Node*> *packetRoute = new vector<Node*>(), int creationTime = 0, int packetSize = 0, int currentNode = 1, Packet *next = NULL);

		// Accessors and Mutators
		vector<Node*> getPacketRoute();
		vector<double> getPacketTimes();
		int getCurrentNode();
		int getPacketSize();
		Packet** getNext();

		void setPacketRoute(vector<Node*> packetRoute);
		void setPacketTimes(vector<double> packetTimes);
		void setPacketSize(int packetSize);
		void setCurrentNode(int currentNode);
		void setNext(Packet *next);

		// Object Functions
		void modifyPacketTimes(double arrivalTime);

	private:
		vector<Node*> packetRoute;
		vector<double> packetTimes;
		int packetSize;
		int currentNode;
		Packet *next;
};

#endif
