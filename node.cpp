#include "node.h"

// constructor of each node
// each node has its own current student
Node::Node(Student* current) {
	student = current;
	next = NULL;
}

// destructor of the student class to prevent segmentation faults
// this will be used when created the delete function
Node::~Node() {
	next = NULL;
}

// setNext is a function that gives a value to the next node in the list
void Node::setNext(Node* newNode) {
	next = newNode;
}

// getNext is a function that will return a node pointer to the next node
Node* Node::getNext() {
	return next;
}
