#ifndef _PACKET_H
#define _PACKET_H

// Importing libraries and declarations
#include <string>
#include <vector>

using namespace std;

// Forward declaration of Node object
class Node;

class Packet {
	public:
		// Constructors
		Packet(vector<Node*> *packetRoute = new vector<Node*>(), int creationTime = 0, int packetSize = 0, int currentNode = 1, Packet *next = NULL);

		// Accessors and Mutators
		vector<Node*> getPacketRoute() const;
		vector<double> getPacketTimes() const;
		int getCurrentNode() const;
		int getPacketSize() const;
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

