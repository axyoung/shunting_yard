#ifndef NODE_H
#define NODE_H
#include <iostream>

// header file for node class

using namespace std;

class Node {

	// in the node class function will be able to get precedence, print out the token, insert tokens, and print out the expressions
	public:
		Node(const char* tok);
		~Node();
		int getPrecedence() const;
		bool isLeftA() const;
		void printToken();
		bool insert(Node* newNode);
		void printPost();
		void printIn();
		void printPre();

	// each node is assigned a precedence, a token, left and right node pointers, and a check for association
	private:
		const char* token;
		int precedence;
		Node* left;
		Node* right;
		bool leftA; // left associative

};
#endif