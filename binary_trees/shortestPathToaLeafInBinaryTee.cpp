#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int ShortestPath(Node* root) {
    // Case 0: If the tree is empty, the minimum depth is 0
    if (!root) return 0;

    // Base case: If the current node is a leaf node (no left or right child),
    // then the minimum depth from this node is 1
    if (!root->left && !root->right) return 1;

    // Initialize left and right depths to a large value (INT_MAX),
    // so we can safely take the minimum later.
    int leftDepth = INT_MAX;
    int rightDepth = INT_MAX;

    // Recurse into the left subtree only if it exists.
    if (root->left) {
        leftDepth = ShortestPath(root->left);
    }

    // Recurse into the right subtree only if it exists.
    if (root->right) {
        rightDepth = ShortestPath(root->right);
    }

    // Return the minimum of the two depths plus one (for the current node)
    return min(leftDepth, rightDepth) + 1;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->left->right = new Node(7);
    
    cout << "Shortest path to a leaf: " << ShortestPath(root) << endl;
    return 0;
}

// visual representation of the tree    
/*
        1
       / \
      2   3
            \
             6
              \
               7
*/