#ifndef ASSIGNMENT9_H_
#define ASSIGNMENT9_H_
#include <iostream>

using namespace std;

struct BSTNode /// BinarySearchTreeNode
{
	int value;
	BSTNode* left = NULL;
	BSTNode* right = NULL;
};

class BST // BinarySearchTree
{
private:
	BSTNode* root;
public:
	//constructor
	BST();
	// function to insert value into the BST
	void insert(int value);
	// helper function to insert a value into the BST
	BSTNode *insert(BSTNode *node, int value);
	// function to remove the value from the BST
	void remove(int value);
	// function to find and return the node with the minimum value
	BSTNode* finMin() const;
	// function to find and return the node with the maximum value
	BSTNode* finMax() const;
	// function to print the pre-order traversal of the BST
	void preOrderTraversal() const;
	// helper function to perform preorder traversal of the BST
	void preOrderTraversal(BSTNode* node) const;
	// function to print the in-order traversal of the BST
	void inOrderTraversal() const;
	// helper function to perform inorder traversal of the BST
	void inOrderTraversal(BSTNode* node) const;
	// function to print the in-order traversal of the BST
	void postOrderTraversal() const;
	// helper function to perform inorder traversal of the BST
	void postOrderTraversal(BSTNode* node) const;
};

BST::BST()
{
	root = NULL;
}

void BST::insert(int value)
{
	root = insert(root, value);
}

BSTNode* BST::insert(BSTNode *node, int value)
{
	if (node == NULL) {
		node = new BSTNode;
		node->value = value;
		node->left = NULL;
		node->right = NULL;
	}

	else {
		if (value < node->value)
			node->left = insert(node->left, value);
		else
			node->right = insert(node->right, value);
	}

	return node;
}

void BST::remove(int value)
{
	if (root != NULL) {
		if (root->value == value) {
			if (root->left == NULL && root->right == NULL)
				root = NULL;
			else if (root->left == NULL)
				root = root->right;
			else if (root->right == NULL)
				root = root->left;
			else {
				BSTNode *p = root->right;
				while (p->left != NULL)
					p = p->left;
				p->left = root->left;
				root = root->right;
			}
			return;
		}

		BSTNode *node = root;
		BSTNode *parent = NULL;
		bool found = false;
		while (node != NULL && !found) {
			if (node->value == value) {
				found = true;
				break;
			}

			parent = node;

			if (value < node->value)
				node = node->left;
			else
				node = node->right;
		}

		if (found) {
			if (node->left == NULL && node->right == NULL) {
				if (parent->left == node)
					parent->left = NULL;
				else
					parent->right = NULL;
			}

			else if (node->left == NULL) {
				if (parent->left == node)
					parent->left = node->right;
				else
					parent->right = node->right;
			}
			else if (node->right == NULL) {
				if (parent->left == node)
					parent->left = node->left;
				else
					parent->right = node->left;
			}
			else {
				BSTNode *p = node->right;
				while (p->left != NULL)
					p = p->left;
				p->left = node->left;
				if (parent->left == node)
					parent->left = node->right;
				else
					parent->right = node->right;
			}
			delete node;
		}
	}
}

BSTNode* BST::finMin() const
{
	if (root == NULL)
		return NULL;
	else {
		BSTNode *curr = root;
		while (curr->left != NULL)
			curr = curr->left;
		return curr;
	}
}

BSTNode* BST::finMax() const
{
	if (root == NULL)
		return NULL;
	else {
		BSTNode *curr = root;
		while (curr->right != NULL)
			curr = curr->right;
		return curr;
	}
}

void BST::preOrderTraversal() const
{
	cout << "preOrderTraversal: ";
	preOrderTraversal(root);
	cout << endl;
}

void BST::preOrderTraversal(BSTNode* node) const
{
	if (node != NULL) {
		cout << node->value << " ";
		preOrderTraversal(node->left);
		preOrderTraversal(node->right);
	}
}

void BST::inOrderTraversal() const
{
	cout << "inOrderTraversal: ";
	inOrderTraversal(root);
	cout << endl;
}

void BST::inOrderTraversal(BSTNode* node) const
{
	if (node != NULL) {
		inOrderTraversal(node->left);
		cout << node->value << " ";
		inOrderTraversal(node->right);
	}
}

void BST::postOrderTraversal() const
{
	cout << "postOrderTraversal: ";
	postOrderTraversal(root);
	cout << endl;
}

void BST::postOrderTraversal(BSTNode* node) const
{
	if (node != NULL) {
		postOrderTraversal(node->left);
		postOrderTraversal(node->right);
		cout << node->value << " ";
	}
}

#endif
