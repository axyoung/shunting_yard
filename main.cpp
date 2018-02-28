/*
 * Alex Young
 * Shunting Yard
 * C++ and data structures (Galbraith)
 * This program will read a mathematical expression entered with infix notation, using spaces between each token. It will then output the postfix expression. You should then be able to output infix, prefix, or postfix notation.
 * It will do this using a stack which will be used to create expression trees
 * Last updated 2/8/2018
 */
 
 // shunting yard algorithm from https://en.wikipedia.org/wiki/Shunting-yard_algorithm
 
#include <iostream>
#include <cstring>
#include <vector>
#include "Node.h"

using namespace std;


int main () {
	cout << "Print out a mathematical expression using numbers and operators." << endl;
	cout << "Your expression will be converted to postfix, prefix and infix." << endl;
	// will need to find out how to parse out input into ints and chars
	char entry[100];
	char* token;
	
	vector <Node*> output;
	vector <Node*> stack;
	
	cin.get(entry, sizeof(entry));
	cin.get();
	// strtok makes a token
	token = strtok(entry, " ");
	while (token != NULL) {
		//cout << token << endl;
		Node* node = new Node(token);
		if (node->getPrecedence() == 0) {
			output.push_back(node);
		}
		else {
			while (!stack.empty && (stack.back->getPrecedence() > node->getPrecedence() ||
					stack.back->getPrecedence() == node->getPrecedence() && stack.back->getLeftA == true ||
					
		
		token = strtok(NULL, " ");
	}
	
// if there on the same level then pop the operation out of the stack in to the output, unless it is ^:

	// basically what is going on is i first use shunting yard to reformat the expression into post fix
	// then i use postfix to build an expression tree using linked lists
	// find next operator then move prev 2 numbers below, and switching the links
	// then using the tree, find the prefix and infix expression and print
	
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
		// when building the binary expression tree
	
	// the idea is to have nodes that have 2 data types, a character and an int, the int is the order of the operator, char is the input, num/operator
	return 0;
}

