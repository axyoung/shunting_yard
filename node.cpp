#include "node.h"

// constructor of each node
// each token has its own precedence according to their level
// also all tokens had left association except for exponents
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
	if (token[0] == '(') {
		precedence = 4;
	}	
	if (token[0] == ')') {
		precedence = 5;
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

void Node::printToken() {
	cout << " " << token;
}

bool Node::isLeftA() const {
	return leftA;
}

// the insert function is used to insert functions into the binary expression tree
// the idea is that it starts at the root and moves to the right, inserting new nodes
// when there is a integer value, you return and go back up
bool Node::insert(Node* newNode) {
	bool inserted = false;
	
	if (precedence == 0) {
		return false;
	}
	
	if (right != NULL) {	
		inserted = right->insert(newNode);
	} else {
		right = newNode;
		inserted = true;
	}
	
	if (inserted) {
		return inserted;
	}
	
	if (left != NULL) {	
		inserted = left->insert(newNode);
	} else {
		left = newNode;
		inserted = true;
	}
	
	return inserted;
}

// print postfix using recursion
void Node::printPost() {
	if (left != NULL) {
		left->printPost();
	}
		
	if (right != NULL) {
		right->printPost();
	}
	
	cout << " " << token;
}


// print infix using recursion
// use parentheses before and after each left and right nodes to show order of operations
// basically putting parentheses around each binary expression and respecting the original hierarchy
void Node::printIn() {
	if (left != NULL) {
		cout << " (";
		left->printIn();
	}
	
	cout << " " << token;	
	
	if (right != NULL) {
		right->printIn();
		cout << " )";
	}
}

// print prefix using recursion
void Node::printPre() {
	cout << " " << token;
	
	if (left != NULL) {
		left->printPre();
	}
		
	if (right != NULL) {
		right->printPre();
	}
}


// this is what my father helped show me with diagrams:
// writen above will look similar to:
	//void Node::print() {
		// print here for prefix
		// if (this->left != NULL) {
		//	this->left->print();
		// }
		// print out here for infix
		// if (this -> right != NULL) {
		//	this->right->print();
		// }
		// print out here for postfix
		
		// the above code will be used backwords starting with the root and moving down to the right
		// when building the binary expression tree - this is in the insert method
	
	// the idea is to have nodes that have 2 data types, a character and an int, the int is the order of the operator, char is the input, num/operator