#ifndef _LINKLISTNODE_H
#define _LINKLISTNODE_H

#include "Node.h"

class LinkListNode {
	public:
		// Constructors
		LinkListNode(Node *listHead = NULL);

		// Accessors and Mutators
		Node ** getListHead();
		void setListHead(Node **listHead);

	private:
		Node *listHead;
};

#endif
