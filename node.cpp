#include "node.h"

// constructor of each node
// each token has its own precedence
Node::Node(const char* tok) {
	token = tok;
	precedence = 0;
	leftA = true;
	if (token[0] == '+' || token[0] == '-') {
		precedence = 1;
	}
	if (token[0] == '*' || token[0] == '/') {
		precedence = 2;
	}
	if (token[0] == '^') {
		precedence = 3;
		leftA = false;
	}
	if (token[0] == ')' || token[0] == '(') {
		precedence = 4;
	}	
	left = NULL;
	right = NULL;
}

// destructor of the node class to prevent segmentation faults
Node::~Node() {
	if (left != NULL) {
		delete left;
	}
	if (right != NULL) {
		delete right;
	}
}

int Node::getPrecedence() const {
	return precedence;
}

bool Node::isLeftA() const {
	return leftA;
}