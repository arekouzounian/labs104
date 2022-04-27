#include "bst.h"

#include <stack>
#include <queue>
#include <set>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <climits>


int depthHelper(Node* curr);

bool isBalanced(Node *root) {
	//Get the heights of the left and right subtrees - helper func?
	//Determine if this node is balanced! If not ret false!

	//Check if there are subtrees under us
	//Are they balanced?

	//If all nodes are balanced return true!

	if (!root) return false; 

	return depthHelper(root->left) == depthHelper(root->right);
}

int depthHelper(Node* curr) {
	if (!curr) return 0;

	return std::max(1 + depthHelper(curr->left), 1 + depthHelper(curr->right));
}

/*

int depthChecker(Node* root);

bool equalPaths(Node * root)
{
    // Add your code below
    if (!root) return false;
    //checks for equal max depths of both left and right subtrees
    //if the one subtree contains a node with larger depth than the
    //other, we know that there cannot be equal paths.
    return depthChecker(root->left) == depthChecker(root->right);
}


int depthChecker(Node* root)
{
    //recursively checks the maximum depth of the given root node
    //by checking both left and right subtrees
    if (!root) return 0;
    return std::max(1 + depthChecker(root->left), 1 + depthChecker(root->right));
}

*/