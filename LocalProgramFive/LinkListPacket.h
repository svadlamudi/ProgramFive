#ifndef _LINKLISTPACKET_H
#define _LINKLISTPACKET_H

#include <string>
#include <vector>
#include "Packet.h"

using namespace std;

class LinkListPacket {
	public:
		// Constructor
		LinkListPacket(Packet* listHead = NULL, int listId = 0);

		// Accessors and Mutators
		Packet** getListHead();
		int getListId();
		void setListHead(Packet **listHead);
		void setListId(int listId);

		// Object Functions
		void insert(Packet *newPacket);
		bool isEmpty();
		void incrementWaitTime(int TIME);
		Packet * getNextNode();
		void printList(FILE *output);

	private:
		Packet *listHead;
		int listId;
};

#endif
