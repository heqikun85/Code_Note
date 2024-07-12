#include "Assignment9.h"

using namespace std;

const int SIZE = 15;

int main()
{
	BST bst;
	int values[SIZE] = { 5, 2, 12, -4, 3, 9, 21, -7, 19, 25, -8, -6, -4, 3, 12 };
	for (int i = 0; i < SIZE; i++)
		bst.insert(values[i]);
	bst.preOrderTraversal(); /// should be 5 2 -4 -7 -8 -6 3 12 9 21 19 25
	bst.inOrderTraversal(); /// should be -8 -7 -6 -4 2 3 5 9 12 19 21 25
	bst.postOrderTraversal(); /// should be -8 -6 7 -4 3 2 9 19 25 21 12 5
	bst.remove(3); /// Node 3 has 0 children --> delete the node and make it NULL;
	bst.remove(-4); /// Node -4 has 1 children --> Link parent to child --> delete the node and make it NULL;
	bst.remove(12); /// Node 12 has 2 children --> findMin for the right subtree --> swap value -> delete
	bst.preOrderTraversal(); /// should be 5 2 -7 -8 -6 19 9 21 25
	bst.inOrderTraversal(); /// should be -8 -7 -6 2 5 9 19 21 25
	bst.postOrderTraversal(); /// should be -8 -6 7 2 9 25 21 19 5
	system ("pause");
	return 0;

}
