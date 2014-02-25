#ifndef _PACKET_H
#define _PACKET_H

#include <string>
#include <vector>

using namespace std;

class Packet {
	public:
		// Constructors
		Packet(vector<int> *packetRoute = new vector<int>(), vector<int> *packetTimes = new vector<int>(), int currentNode = 0, Packet *next = NULL);

		// Accessors and Mutators
		vector<int> getPacketRoute();
		vector<int> getPacketTimes();
		int getCurrentNode();
		Packet** getNext();
		void setPacketRoute(vector<int> packetRoute);
		void setPacketTimes(vector<int> packetTimes);
		void setCurrentNode(int currentNode);
		void setNext(Packet *next);

	private:
		vector<int> packetRoute;
		vector<int> packetTimes;
		int currentNode;
		Packet *next;
};

#endif
