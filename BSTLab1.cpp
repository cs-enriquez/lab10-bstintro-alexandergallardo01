#include <iostream>

using namespace std;

// Implement the node class we will need for our Binary Search Tree
class Node {
	public:
	int key;
	Node *right;
	Node *left;
		// the Node should contain
		// 	- an integer "key" that holds the value of the Node
		// 	- a pointer to each child possible child node ("right" and "left")
    Node(int n = 0){
    key = n;
	right = nullptr;
	left = nullptr;
	}

		// Write a constructor for the Node
		// input: only an integer value for "key", no pointer arguments
		// 		right and left pointers should be null

};


// Use this function to create a Binary Search Tree (BST) tree with the following values
// {13, 0, 7, 6, 21, 15, -2, 12, 99, 18, 19, -1}
Node* createTree() {
	Node* root = new Node(13);

    // Insert nodes while maintaining BST properties
    int values[] = {0, 7, 6, 21, 15, -2, 12, 99, 18, 19, -1};

    for (int value : values) {
        Node* current = root;
        while (true) {
            if (value < current->value) {
                if (current->left == nullptr) {
                    current->left = new Node(value);
                    break;
                } else {
                    current = current->left;
                }
            } else {
                if (current->right == nullptr) {
                    current->right = new Node(value);
                    break;
                } else {
                    current = current->right;
                }
            }
        }
    }

    return root;
}

// Write a function that will search the BST for a target value
//	input: integer target to search for,
			// pointer to root Node
// 	returns: true or false depending on if the value is found
// You should write this function recursively! What is the base case? What is the general case?
bool searchTree(int target, Node* root) {
	TreeNode*current = root;
if(current == nullptr){
        return false;
    }
if(root->key == target){
	return true;
}

if(root->key < target){
return searchTree(target, root->right);
}
if(root->key > target){
return searchTree(target, root->left);
}

	
}

// Write a function that will return the total number of Nodes in the tree
// 	input: pointer to the root Node
// 	returns: number of nodes currently in the tree
// You should write this function recursively!
int treeSize(Node* root) {
    if(root == nullptr){
        return;
    }
    else{
     return 1 + treeSize(root->left) + treeSize(root->right);   
}
    }

}

// BONUS! Write a function that will determine the height of the tree
int treeHeight(Node* root) {
	 if (root == nullptr) {
        return -1; // Conventionally, height of an empty tree is -1
    }

    // General case: Height is 1 + maximum of left and right subtree heights
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);

    return 1 + std::max(leftHeight, rightHeight);
}
}
