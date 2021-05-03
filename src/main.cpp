/** --------------------------- 
* @file		main.cpp
* @author	Charlie Welsh
* @version	1.0
*
* CS260-01 - Assignment 3
*	Demoes a binary search tree list.
*
* --------------------------- */

#include <iostream>
#include <string>
#include "BinaryTree.cpp"

int main() {
	printf("CS260, A5-Binary Trees\nAuthor: Charlie Welsh\n");
	BinaryTree<std::string> stringTree;
	// Setting the initial values of the BinaryTree
	std::string initialStrings[12] = { "Jynx", "Charmander", "Snorlax", "Diglett", "Kakuna", "Meowth", "Pikachu", "Blastoise", "Squirtle", "Ivysaur", "Bulbasaur", "Abra" };
	for (int i = 0; i < sizeof(initialStrings)/sizeof(initialStrings[0]); i++) {
		stringTree.add(initialStrings[i]);
	}
	
	stringTree.printInOrder();
	stringTree.printPostOrder();
	stringTree.printPreOrder();
	
	stringTree.removeAll();
		
	stringTree.printInOrder();
}
