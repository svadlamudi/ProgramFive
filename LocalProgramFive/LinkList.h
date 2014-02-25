#ifndef _LINKLIST_H
#define _LINKLIST_H

#include "Packet.h"
#include <string>

using namespace std;

class LinkList {
	public:
		// Constructor
		LinkList(Packet *listHead = NULL, string listName = "");

		// Accessors and Mutators
		Packet** getListHead();
		string getListName();
		void setListHead(Packet **listHead);
		void setListName(string listName);

		// Object Functions
		void insert(vector<int> *packetRoute, vector<int> *packetTimes);
		Packet * getNextNode();
		void printList(FILE *output = NULL);

	private:
		Packet *listHead;
		string listName;
};

#endif
