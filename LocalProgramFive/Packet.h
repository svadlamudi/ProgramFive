#ifndef _PACKET_H
#define _PACKET_H

#include <string>
#include <vector>

using namespace std;

class Packet {
	public:
		// Constructors
		Packet(vector<int> *packetRoute = new vector<int>(), vector<int> *packetTimes = new vector<int>(), Packet *next = NULL);

		// Accessors and Mutators
		vector<int> getPacketRoute();
		vector<int> getPacketTimes();
		Packet** getNext();
		void setPacketRoute(vector<int> packetRoute);
		void setPacketTimes(vector<int> packetTimes);
		void setNext(Packet *next);

	private:
		vector<int> packetRoute;
		vector<int> packetTimes;
		Packet *next;
};

#endif
