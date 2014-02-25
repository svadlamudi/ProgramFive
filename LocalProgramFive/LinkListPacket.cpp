#include "LinkListPacket.h"

using namespace std;

// Constructor
LinkListPacket::LinkListPacket(Packet *listHead, string listName) {
	this->listHead = listHead;
	this->listName = listName;
}

// Accessors and Mutators
Packet ** LinkListPacket::getListHead() {
	return &(this->listHead);
}
string LinkListPacket::getListName() {
	return this->listName;
}

void LinkListPacket::setListHead(Packet **listHead) {
	this->listHead = *listHead;
}
void LinkListPacket::setListName(string listName) {
	this->listName = listName;
}

// Object Functions

/*
 * Sai Kiran Vadlamudi  C05
 * Create and Add new node to list
 *
 * Parameters:
 *	packetRoute: a vector of integers representing the path IDs
 *	packetTimes: a vector of integers representing the time of arrival at each node in the path
 *
 * Return:
 *	void
 */
void LinkListPacket::insert(vector<int> *packetRoute, vector<int> *packetTimes) {
	Packet **temp = &(this->listHead);
	Packet *newPacket = new Packet(packetRoute, packetTimes);
	
	while (*temp != NULL && !packetTimes->empty())
	{
		if ((*temp)->getPacketTimes().front() > newPacket->getPacketTimes().front())
		{
			break;
		}

		temp = (*temp)->getNext();
	}

	newPacket->setNext(*temp);
	*temp = newPacket;
}

/*
 * Sai Kiran Vadlamudi  C05
 * Return the first node in the list
 *
 * Parameters:
 *	None
 *
 * Return:
 *	Packet*
 */
Packet * LinkListPacket::getNextNode() {
	if (this->listHead != NULL) {
		Packet *temp = this->listHead;
		this->listHead = *((this->listHead)->getNext());
		return temp;
	} 
	else
	{
		return NULL;
	}
}

/*
 * Sai Kiran Vadlamudi  C05
 * Print the activating list
 *
 * Parameters:
 *	None
 *
 * Return:
 *	void
 */
void LinkListPacket::printList(FILE *output) {
	Packet *temp = this->listHead;

	while (temp != NULL && output != NULL)
	{
		fprintf(output, "| Source: ");
		for (unsigned i = 0; i < temp->getPacketRoute().size(); i++)
		{
			fprintf(output, "%3d", temp->getPacketRoute().at(i));
		}
		fprintf(output, " |");

		fprintf(output, " Times: ");
		for (unsigned i = 0; i < temp->getPacketTimes().size(); i++)
		{
			fprintf(output, "%3d", temp->getPacketTimes().at(i));
		}

		fprintf(output, " |\n");

		temp = *(temp->getNext());
	}

	while (temp != NULL && output == NULL)
	{
		printf("| Source: ");
		for (unsigned i = 0; i < temp->getPacketRoute().size(); i++)
		{
			printf("%3d", temp->getPacketRoute().at(i));
		}
		printf(" |");

		printf(" Times: ");
		for (unsigned i = 0; i < temp->getPacketTimes().size(); i++)
		{
			printf("%3d", temp->getPacketTimes().at(i));
		}

		printf(" |\n");

		temp = *(temp->getNext());
	}
}

