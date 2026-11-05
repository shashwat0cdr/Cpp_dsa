
#include <iostream>
#include <vector>
using namespace std;

// Binary Tree Node
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

class Solution {
public:

    // Traverse Left Boundary
    void TraverseLeft(Node* root, vector<int>& ans) {

        if (root == NULL ||
            (root->left == NULL && root->right == NULL)) {
            return;
        }

        ans.push_back(root->data);

        if (root->left) {
            TraverseLeft(root->left, ans);
        }
        else {
            TraverseLeft(root->right, ans);
        }
    }

    // Traverse Leaf Nodes
    void traverseLeaf(Node* root, vector<int>& ans) {

        if (root == NULL) {
            return;
        }

        if (root->left == NULL && root->right == NULL) {
            ans.push_back(root->data);
            return;
        }

        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }

    // Traverse Right Boundary
    void traverseRight(Node* root, vector<int>& ans) {

        if (root == NULL ||
            (root->left == NULL && root->right == NULL)) {
            return;
        }

        if (root->right) {
            traverseRight(root->right, ans);
        }
        else {
            traverseRight(root->left, ans);
        }

        // Add after recursive call for reverse order
        ans.push_back(root->data);
    }

    // Boundary Traversal
    vector<int> boundary(Node* root) {

        vector<int> ans;

        if (root == NULL) {
            return ans;
        }

        // Add root
        ans.push_back(root->data);

        // Left Boundary
        TraverseLeft(root->left, ans);

        // Leaf Nodes
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);

        // Right Boundary
        traverseRight(root->right, ans);

        return ans;
    }
};

// Main Function
int main() {

    /*
               1
             /  \
            2    3
           / \  / \
          4  5  6  7
            / \
            8  9
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);

    Solution obj;

    vector<int> ans = obj.boundary(root);

    cout << "Boundary Traversal: ";

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
