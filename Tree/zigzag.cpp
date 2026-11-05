#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if (root == nullptr) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;

        while (!q.empty()) {

            int size = q.size();

            vector<int> result(size);

            for (int i = 0; i < size; i++) {

                TreeNode* frontNode = q.front();
                q.pop();

                int index = leftToRight ? i : size - i - 1;

                result[index] = frontNode->val;

                if (frontNode->left) {
                    q.push(frontNode->left);
                }

                if (frontNode->right) {
                    q.push(frontNode->right);
                }
            }

            ans.push_back(result);

            leftToRight = !leftToRight;
        }

        return ans;
    }
};

int main() {

    // Creating Binary Tree
    /*
              3
             / \
            9   20
               /  \
              15   7
    */

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;

    vector<vector<int>> ans = obj.zigzagLevelOrder(root);

    cout << "Zigzag Level Order Traversal:" << endl;

    for (auto level : ans) {
        for (auto node : level) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}