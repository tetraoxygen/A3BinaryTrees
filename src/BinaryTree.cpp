/** --------------------------- 
* @file		BinaryTree.cpp
* @author	Charlie Welsh
* @version	1.0
*
* CS162-01 - Assignment 4.2
*	Implements the BinaryTree class.
*
* --------------------------- */

#include "BinaryTree.h"

// --------------------------- 
template<class T> BinaryTree<T>::BinaryTree() {
	head = nullptr;
};

// --------------------------- 
template<class T> BinaryTree<T>::~BinaryTree() {
	removeAll();
}

// --------------------------- 
template <class T> void BinaryTree<T>::printInOrder(Node<T>* node, int depth) {

	// Automatically sets the Node to the head of the list if none is specified.
	if (!node) {
		node = this->head;
	}
	// Halt execution if the current node is a nullptr.
	if (!node) return;
	
	if (node->left) printInOrder(node->left, depth + 1);
	std::cout << node->data << "(" << depth << ") ";
	if (node->right) printInOrder(node->right, depth + 1);
	
	if (node == this->head) {
		std::cout << std::endl;
	}
}

// --------------------------- 
template <class T> void BinaryTree<T>::printPostOrder(Node<T>* node, int depth) {

	// Automatically sets the Node to the head of the list if none is specified.
	if (!node) {
		node = this->head;
	}
	// Halt execution if the current node is a nullptr.
	if (!node) return;
	
	if (node->left) printPostOrder(node->left, depth + 1);
	if (node->right) printPostOrder(node->right, depth + 1);
	std::cout << node->data << "(" << depth << ") ";
	
	if (node == this->head) {
		std::cout << std::endl;
	}
}

// --------------------------- 
template <class T> void BinaryTree<T>::printPreOrder(Node<T>* node, int depth) {

	// Automatically sets the Node to the head of the list if none is specified.
	if (!node) {
		node = this->head;
	}
	// Halt execution if the current node is a nullptr.
	if (!node) return;
	
	std::cout << node->data << "(" << depth << ") ";
	if (node->left) printPreOrder(node->left, depth + 1);
	if (node->right) printPreOrder(node->right, depth + 1);
	
	if (node == this->head) {
		std::cout << std::endl;
	}
}

// --------------------------- 
template <class T> bool BinaryTree<T>::add(T data) {

	if (head == nullptr) {
		head = new Node<T> { .data = data, .left = nullptr, .right = nullptr };
		return true;
	}
	
	Node<T>* current = this->head;
	
	bool hasBeenAdded = false;
	
	while (!hasBeenAdded) {
		if (data > current->data) {
			if (current->right == nullptr) {
				current->right = new Node<T> { .data = data };
				hasBeenAdded = true;
			} else {
				current = current->right;
			}
		} else if (data < current->data) {
			if (current->left == nullptr) {
				current->left = new Node<T> { .data = data };
				hasBeenAdded = true;
			} else {
				current = current->left;
			}
		} else {
			return false; // The value already exists, return false.
		}
	}
	
	return true;
}

// --------------------------- 
template <class T> int BinaryTree<T>::count() {
	// TODO: Implement this
	
	// int count = 0;
	// Node<T>* current = head;
	// while (current != nullptr) {
	// 	count = count += 1;
	// 	
	// 	current = current->next;
	// }
	// return count;
}

// --------------------------- 
template <class T> bool BinaryTree<T>::remove(T data) {
	// TODO: Implement this
	
	// Node<T>* current = head;
	// Node<T>* previous = nullptr;
	// while (current != nullptr) {
	// 	Node<T>* next = current->next;
	// 	if (data == current->data) {
	// 		if (previous) {
	// 			previous->next = next;
	// 		} else {
	// 			head = next;
	// 		}
	// 		delete current;
	// 		return true;
	// 	}
	// 	
	// 	previous = current;
	// 	current = next;
	// }
	// return false;
}

// --------------------------- 
// template <class T> int BinaryTree<T>::find(T data) {
// 	// TODO: Implement this
// 	
// 	// int count = 0;
// 	// Node<T>* current = head;
// 	// while (current != nullptr) {
// 	// 	count = count += 1;
// 	// 	
// 	// 	if (data == current->data) {
// 	// 		return count;
// 	// 	}
// 	// 		
// 	// 	current = current->next;
// 	// }
// 	// return 0;
// }

// --------------------------- 
template <class T> void BinaryTree<T>::removeAll(Node<T>* node) {
	// Don't bother doing anything if the tree is already empty
	if (this->head == nullptr) {
		return;
	}
	
	// Automatically sets the Node to the head of the list if none is specified.
	if (!node) {
		node = this->head;
	}
	
	if (node->left) removeAll(node->left);
	if (node->right) removeAll(node->right);
	
	// Delete the node
	delete node;
	// If we're back at the head, set it to a nullptr after deleting it. 
	if (this->head == node) {
		this->head = nullptr;
	}
}