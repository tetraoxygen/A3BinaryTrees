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
		int count();
		
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
		
		
		//  Do we need this?
		/**
		*	Finds a piece of data's position in the list.
		*		@param data - the data to find
		*		@param index - an index value (passed by reference) to assign the index to.
		*		@return true if the data can be found, false otherwise
		*/
		// bool find(T data, int index); 
		
		/**
		*	Removes all elements in the tree.
		*/
		void removeAll(Node<T>* node = nullptr);
		
	private:
		Node<T>* head;
};

#endif