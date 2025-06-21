#include <iostream>
#include <queue>

using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode *buildTree(int arr[], int n)
{
    queue<TreeNode *> q;
    TreeNode *root = new TreeNode(arr[0]);
    q.push(root);
    int i = 1;
    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();
        if (i < n)
        {
            curr->left = new TreeNode(arr[i]);
            q.push(curr->left);
            i++;
        }
        if (i < n)
        {
            curr->right = new TreeNode(arr[i]);
            q.push(curr->right);
            i++;
        }
    }
    return root;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    // it also called as level order traversal
    TreeNode *root = buildTree(arr, n);
    cout << "Binary Tree Representation:" << endl;
    return 0;
}