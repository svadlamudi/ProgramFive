#ifndef _LINKLISTPACKET_H
#define _LINKLISTPACKET_H

#include <string>
#include <vector>
#include "Packet.h"

using namespace std;

class LinkListPacket {
	public:
		// Constructor
		LinkListPacket(Packet* listHead = NULL);

		// Accessors and Mutators
		Packet** getListHead();
		void setListHead(Packet **listHead);

		// Object Functions
		void insert(Packet *newPacket);
		bool isEmpty();
		void incrementWaitTime(int TIME);
		Packet * getNextNode();
		void printList(FILE *output);

	private:
		Packet *listHead;
};

#endif
