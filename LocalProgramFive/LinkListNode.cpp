#include "LinkListNode.h"

// Constructors
LinkListNode::LinkListNode(Node *listHead) {
	this->listHead = listHead;
}

// Accessors and Mutators
Node ** LinkListNode::getListHead() {
	return &(this->listHead);
}

void LinkListNode::setListHead(Node **listHead) {
	this->listHead = *listHead;
}

// Object Functions

