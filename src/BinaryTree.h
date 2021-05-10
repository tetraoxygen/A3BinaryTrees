/** --------------------------- 
* @file		BinaryTree.h
* @author	Charlie Welsh
* @version	1.0
*
* CS260-01 - Assignment 3
*	Headers for a binary search tree.
*
* --------------------------- */

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <string>

template <class T> struct Node {
	T data;
	Node* left;
	Node* right;
};

template <class T> class BinaryTree {
	public: 
		/**
		*	Initializes a BinaryTree with the head set to a Node object 
		*/
		BinaryTree();
		
		/**
		*	Destructor for BinaryTree; it deletes all the Nodes in the list. 
		*/
		~BinaryTree();
		
		/**
		*	Prints the value of all members of the tree, space delimited, using recursive inorder traversal.
		*/
		void printInOrder(Node<T>* node = nullptr, int depth = 0);
		
		/**
		*	Prints the value of all members of the tree, space delimited, using recursive postorder traversal.
		*/
		void printPostOrder(Node<T>* node = nullptr, int depth = 0);
		
		/**
		*	Prints the value of all members of the tree, space delimited, using recursive preorder traversal.
		*/
		void printPreOrder(Node<T>* node = nullptr, int depth = 0);
		
		/**
		*	Returns the number of members in the list.
		*		@return the number of members in the list
		*/
		bool count(int &counter, Node<T>* node = nullptr);
		
		/**
		*	Inserts data into the binary tree.
		*		@param data - the data to insert
		*		@return true if the item can be inserted, false if it can't.
		*/
		bool add(T data);
		
		/**
		*	Removes an element from the list. 
		*		@param data - the element to remove
		*		@return true if the item can be removed, false if it can't.
		*/
		bool remove(T data);
		
		/**
		*	Gets if the list is empty or not. True if it is, false otherwise. =
		*		@return true if the tree is empty, false otherwise
		*/
		bool isEmpty();
		
		/**
		*	Finds a piece of data's position in the list.
		*		@param data - the data to find
		*		@param index - an index value (passed by reference) to assign the index to.
		*		@return true if the data can be found, false otherwise
		*/
		Node<T>* find(T data);
		
		/**
		*	Removes all elements in the tree.
		*/
		void removeAll(Node<T>* node = nullptr);
		
	private:
		Node<T>* head;
};

// Implementations

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
template <class T> bool BinaryTree<T>::count(int &counter, Node<T>* node) {
	// Automatically sets the Node to the head of the list if none is specified.
	if (!node) {
		node = this->head;
	}
	// Halt execution if the current node is a nullptr.
	if (!node) {
		return true;
	}
	
	counter += 1;
	
	if (node->left) count(counter, node->left);
	if (node->right) count(counter, node->right);
	
	if (node == this->head) {
		return true;
	}
	return false;
}

// --------------------------- Doesn't work because I did this late at night as my computer was having issues
template <class T> bool BinaryTree<T>::remove(T data) {
	
	Node<T>* nodeDel = this->find(data);
	
	if (head == nullptr) {
		return false;
	}
	
	if (!nodeDel) {
		return false;
	}

	Node<T>* parent = this->head;
	bool parentFound = false;
	while (!parentFound) {
		if (parent->left) {
			if (parent->left->data == data) {
				parentFound = true;
				parent = parent->left;
			}
		} else if (parent->right) {
			if (parent->right->data == data) {
				parentFound = true;
				parent = parent->right;
			}
		} else {
			if (data > parent->data) {
				if (parent->right != nullptr) {
					parent = parent->right;
				} else if (parent->left != nullptr) {
					parent = parent->left;
				}
			} else if (data < parent->data) {
				if (parent->left != nullptr) {
					parent = parent->left;
				} else if (parent->right != nullptr) {
					parent = parent->right;
				}
			}
		}
	}
		
	std::cout << nodeDel << std::endl;
	if (!nodeDel->left && !nodeDel->right) {
		if (parent->left == nodeDel) {
			parent->left = nullptr;
		} else if (parent->right == nodeDel) {
			parent->right = nullptr;
		}
		delete nodeDel;
	} else if (nodeDel->left && nodeDel->right) {
		bool successorFound = false;
		Node<T>* current = head->right;
		Node<T>* prev = nullptr;
		while (!successorFound) {
			if (current->left) {
				prev = current;
				current = current->left;
			} else if (current->right) {
				prev = current;
				current = current->right;
			} else {
				successorFound = true;
			}
		}
		nodeDel->data = current->data;
		if (prev->left == current) {
			prev->left = nullptr;
			delete current;
		} else if (prev->right == current) {
			prev->right = nullptr;
			delete current;
		}
	} else if (nodeDel->left) {
		nodeDel->data = nodeDel->left->data;
		delete nodeDel->left;
		nodeDel->left = nullptr;
	} else if (nodeDel->right) {
		nodeDel->data = nodeDel->right->data;
		delete nodeDel->right;
		nodeDel->right = nullptr;
	}
	return true;
}

// --------------------------- 
template <class T> bool BinaryTree<T>::isEmpty() {
	return this->head == nullptr;
}

//--------------------------- 
template <class T> Node<T>* BinaryTree<T>::find(T data) {
	if (head == nullptr) {
		return nullptr;
	}
	
	Node<T>* current = this->head;
	bool hasBeenFound = false;
	
	while (!hasBeenFound) {
		if (data == current->data) {
			hasBeenFound = true;
			return current; // The value already exists, return it.
		} else if (!current->left && !current->right) {
			return nullptr;
		} else {
			if (data > current->data) {
				if (current->right != nullptr) {
					current = current->right;
				}
			} else if (data < current->data) {
				if (current->left != nullptr) {
					current = current->left;
				}
			}
		}
		
	}
	
	return nullptr;
}

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

#endif