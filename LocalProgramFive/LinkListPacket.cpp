#include "LinkListPacket.h"

using namespace std;

// Constructors

/*
 * Sai Kiran Vadlamudi  C05
 * Create and return a pointer to new LinkListPacket object
 * 
 * Parameters:
 *	listHead: pointer to the head of the linked list of Packets
 *	
 * Return:
 *	LinkListPacket*
 */
LinkListPacket::LinkListPacket(Packet *listHead) {
	this->listHead = listHead;
}

// Accessors and Mutators

/* Return a pointer to the head of this LinkListPacket */
Packet ** LinkListPacket::getListHead() {
	return &(this->listHead);
}

/* Set the head of this LinkListPacket to the dereferenced pointer of the given double pointer to a Packet */
void LinkListPacket::setListHead(Packet **listHead) {
	this->listHead = *listHead;
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
void LinkListPacket::insert(Packet *newPacket) {
	
	Packet **temp = &(this->listHead);
	
	while (*temp != NULL && !(newPacket->getPacketTimes()).empty())
	{
		if ((*temp)->getPacketTimes().at((*temp)->getCurrentNode()) > newPacket->getPacketTimes().at(newPacket->getCurrentNode()))
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
 * Return true if this list is empty
 * 
 * Parameters:
 *	None
 *
 * Return:
 *	bool
 */
bool LinkListPacket::isEmpty() {
	
	if (listHead == NULL)
		return true;
	else
		return false;
}

/*
 * Sai Kiran Vadlamudi  C05
 * Increment the arrival time of the packets waiting in the queue
 * 
 * Parameters:
 *	TIME: current time of the simulation
 *	
 * Return:
 *	void
 */
void LinkListPacket::incrementWaitTime(int TIME) {
	
	Packet *temp = this->listHead;
	
	while (temp != NULL && TIME > temp->getPacketTimes().at(temp->getCurrentNode()))
	{
		temp->modifyPacketTimes(temp->getPacketTimes().at(temp->getCurrentNode()) + 1);

		temp = *temp->getNext();
	}
}

/*
 * Sai Kiran Vadlamudi  C05
 * Return the first node in the list. NULL if list is empty.
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
