/*
 * Alex Young
 * Shunting Yard
 * C++ and data structures (Galbraith)
 * This program will read a mathematical expression entered with infix notation, using spaces between each token. It will then output the postfix expression. You should then be able to output infix, prefix, or postfix notation.
 * It will do this using a stack which will be used to create expression trees
 * Last updated 2/8/2018
 */
 
 // shunting yard algorithm from https://en.wikipedia.org/wiki/Shunting-yard_algorithm
 // also my father helped me create the try catch function as well as the memory clearing
 // he also helped me to understand how to create and print the binary expression tree with recursion 
 
#include <iostream>
#include <cstring>
#include <vector>
#include "Node.h"

using namespace std;

void printVector(const vector<Node*>& v, const char* msg, const char* msg2 = "\n");


int main () {
	
	cout << "Print out a mathematical expression using numbers and operators." << endl;
	cout << "Your expression will be converted to postfix, prefix and infix." << endl;
	// will need to find out how to parse out input into ints and chars
	char entry[100];
	char* token;
	
	// I use vectors to store the output and the stack
	vector <Node*> output;
	vector <Node*> stack;
	// the root node is null
	Node* root = NULL;
	
	cin.get(entry, sizeof(entry));
	cin.get();
	// strtok makes a token
	token = strtok(entry, " ");
	// try catch used to find errors and go to the end
	try {
		while (token != NULL) {
			//cout << token << endl; // debug
			Node* node = new Node(token);
			if (node->getPrecedence() == 0) {
				output.push_back(node);
			}
			
			else {
				// while ((there is an operator at the top of the operator stack with greater precedence) or
				//        (the operator at the top of the operator stack has equal precedence and the operator is left associative))
				//    and (the operator at the top of the stack is not a left bracket):
				while (!stack.empty()) {
					Node* top = stack.back(); // this is the operator on the top of the stack
					
					if (top->getPrecedence() == 4) { // this precedence means that it is a left parenthesis
						break;
					}
					if (top->getPrecedence() < node->getPrecedence()) {
						break;
					}
					if (top->getPrecedence() == node->getPrecedence() && top->isLeftA() != true) {
						break;
					}
					
					// pop operators from the operator stack, onto the output queue
					output.push_back(top);
					stack.pop_back();
				}
				// push the read operator onto the operator stack
				if (node->getPrecedence() < 4) {
					stack.push_back(node);
				}
			}
			
			// if the token is a left bracket (i.e. "("), then: push it onto the operator stack.
			
			if (node->getPrecedence() == 4) {
				stack.push_back(node);
			}
			
			
			// 	if the token is a right bracket (i.e. ")"), then:
			if (node->getPrecedence() == 5) {
				// while the operator at the top of the operator stack is not a left bracket:
				while (!stack.empty()) {
					if (stack.back()->getPrecedence() == 4) {
						break;	
					}
					// pop operators from the operator stack onto the output queue.
					output.push_back(stack.back());
					stack.pop_back();
				}
				
				// if the stack runs out without finding a left bracket, then there are mismatched parentheses.
				if (stack.empty()) {
					throw ("Mismatched parentheses detected.");
				}
				
				// pop the left bracket from the stack.
				stack.pop_back();	
			}
			
			//cout << token << " ";
			//printVector(output, "[Output]", " ");
			//printVector(stack, "[Stack]");
			
			token = strtok(NULL, " ");
		}

		//cout << "Before Loop Two" << endl;
		//printVector(output, "[Output]", " ");
		//printVector(stack, "[Stack]");
		
		
		// there are no more tokens to read:
		// while there are still operator tokens on the stack:
		while (!stack.empty()) {
			// if the operator token on the top of the stack is a bracket
			//stack.back()->printToken();
			if (stack.back()->getPrecedence() > 3) {
				throw ("Mismatched parentheses detected.");
			}
			// pop the operator onto the output queue.
			output.push_back(stack.back());
			stack.pop_back();
		}

		// printing out in postfix directly from algorithm
		//printVector(output, "[Postfix]");
		
		// building the binary expression tree
		while (!output.empty()) {
			if (root == NULL) {
				root = output.back();
			} else {
				root->insert(output.back());
			}
			output.pop_back();
		}
		cout << "[Postfix]";
		root->printPost();
		cout << endl;
		
		cout << "[Infix]";
		root->printIn();
		cout << endl;
		
		cout << "[Prefix]";
		root->printPre();
		cout << endl;
	
	} catch (const char* message) {
		cout << message << endl;
	}
	
	// code below is used to free memory
	while (!stack.empty()) {
		delete stack.back();
		stack.pop_back();
	}
	
	while (!output.empty()) {
		delete output.back();
		output.pop_back();
	}
	
	if (root != NULL) {
		delete root;
	}
	
	return 0;
}

// this is a function I used for debugging, it prints out the tokens in the vectors
// used this to print out stack and output
void printVector(const vector<Node*>& v, const char* msg, const char* msg2) {
	cout << msg;
	for (unsigned i = 0; i < v.size(); i++) {
		v[i]->printToken();
	}
	cout << msg2;
}