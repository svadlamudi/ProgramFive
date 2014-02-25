#ifndef _LINKLISTPACKET_H
#define _LINKLISTPACKET_H

#include "Packet.h"
#include <string>

using namespace std;

class LinkListPacket {
	public:
		// Constructor
		LinkListPacket(Packet *listHead = NULL, int listId = 0);

		// Accessors and Mutators
		Packet** getListHead();
		int getListId();
		void setListHead(Packet **listHead);
		void setListId(int listId);

		// Object Functions
		void insert(vector<int> *packetRoute, vector<int> *packetTimes);
		Packet * getNextNode();
		void printList(FILE *output = NULL);

	private:
		Packet *listHead;
		int listId;
};

#endif
