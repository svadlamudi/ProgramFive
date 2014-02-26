#ifndef _PACKET_H
#define _PACKET_H

#include "Node.h"
#include <string>
#include <vector>

using namespace std;

class Packet {
	public:
		// Constructors
		Packet(vector<int> *packetRoute = new vector<int>(), vector<int> *packetTimes = new vector<int>(), int packetSize = 0, int currentNode = 0, Packet *next = NULL);

		// Accessors and Mutators
		vector<int> getPacketRoute();
		vector<int> getPacketTimes();
		int getCurrentNode();
		int getPacketSize();
		Packet** getNext();
		void setPacketRoute(vector<int> packetRoute);
		void setPacketTimes(vector<int> packetTimes);
		void setPacketSize(int packetSize);
		void setCurrentNode(int currentNode);
		void setNext(Packet *next);

		// Object Functions
		double propagationTime(Node recieveNode);
	private:
		vector<int> packetRoute;
		vector<int> packetTimes;
		int packetSize;
		int currentNode;
		Packet *next;
};

#endif
