/*
 * Alex Young
 * Shunting Yard
 * C++ and data structures (Galbraith)
 * This program will read a mathematical expression entered with infix notation, using spaces between each token. It will then output the postfix expression. You should then be able to output infix, prefix, or postfix notation.
 * It will do this using a stack which will be used to create expression trees
 * Last updated 2/8/2018
 */
#include <iostream>

using namespace std;

int main () {

// if there on the same level then pop the operation out of the stack in to the output, unless it is ^:

	// basically what is going on is i first use shunting yard to reformat the expression into post fix
	// then i use postfix to build an expression tree using linked lists
	// find next operator then move prev 2 numbers below, and switching the links
	// then using the tree, find the prefix and infix expression and print
	return 0;
}

// yay I finished
