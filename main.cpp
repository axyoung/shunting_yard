/*
 * Alex Young
 * Shunting Yard
 * C++ and data structures (Galbraith)
 * This program will read a mathematical expression entered with infix notation, using spaces between each token. It will then output the postfix expression. You should then be able to output infix, prefix, or postfix notation.
 * It will do this using a stack which will be used to create expression trees
 * Last updated 2/8/2018
 */
#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

//void printPost(Node* current);
//void printPre(Node* current);
//void printIn(Node* current);

int main () {
	cout << "Print out a mathematical expression using numbers and operators." << endl;
	cout << "Your expression will be converted to postfix, prefix and infix." << endl;
	// will need to find out how to parse out input into ints and chars
	char input[100];
	cin >> input;
	input.Remove(" ");
	cout << input << endl;
	
	Node* current = head;
	for (int i = 0; i < sizeof(input); i++) {
		if (current != NULL) {
			current->c = input[i];
		}
		if (current->getNext() != NULL) {
			current = current->getNext();
		}
	}
		
	//cout << "[Postfix] " << printPost(); << endl;
	//cout << "[Prefix] " << printPre(); << endl;
	//cout << "[Infix] " << printIn(); << endl;

// if there on the same level then pop the operation out of the stack in to the output, unless it is ^:

	// basically what is going on is i first use shunting yard to reformat the expression into post fix
	// then i use postfix to build an expression tree using linked lists
	// find next operator then move prev 2 numbers below, and switching the links
	// then using the tree, find the prefix and infix expression and print
	
	
	// the idea is to have nodes that have 2 data types, a character and an int, the int is the order of the operator, char is the input, num/operator
	return 0;
}

// yay I finished
