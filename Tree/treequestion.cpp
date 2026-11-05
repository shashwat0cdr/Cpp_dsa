// tree questions practice
// 1. Height of Binary Tree
// 2. Diameter of Binary Tree (Brute Force and Optimized)
// 3. Balanced Binary Tree (Brute Force and Optimized)
// 4. Identical / Same Tree
// 5. Sum Tree (Optimized)

#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

// ==========================================
// TREE NODE STRUCTURE
// ==========================================

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

// ==========================================
// 1. HEIGHT OF BINARY TREE
// LEETCODE 104
// ==========================================

int height(TreeNode* root) {

    if (root == nullptr) {
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    return max(left, right) + 1;
}

// ==========================================
// 2. DIAMETER - BRUTE FORCE
// LEETCODE 543 - O(N^2)
// ==========================================

int diameterBrute(TreeNode* root) {

    if (root == nullptr) {
        return 0;
    }

    int op1 = diameterBrute(root->left);
    int op2 = diameterBrute(root->right);

    int op3 = height(root->left) + height(root->right);

    return max(op3, max(op1, op2));
}

// ==========================================
// 3. DIAMETER - OPTIMIZED
// LEETCODE 543 - O(N)
// ==========================================

int diameterOptimized(TreeNode* root, int &diameter) {

    if (root == nullptr) {
        return 0;
    }

    int left = diameterOptimized(root->left, diameter);
    int right = diameterOptimized(root->right, diameter);

    diameter = max(diameter, left + right);

    return max(left, right) + 1;
}

int getOptimizedDiameter(TreeNode* root) {

    int diameter = 0;

    diameterOptimized(root, diameter);

    return diameter;
}

// ==========================================
// 4. BALANCED TREE - BRUTE FORCE
// LEETCODE 110 - O(N^2)
// ==========================================

bool isBalancedBrute(TreeNode* root) {

    if (root == nullptr) {
        return true;
    }

    bool left = isBalancedBrute(root->left);
    bool right = isBalancedBrute(root->right);

    bool difference =
        abs(height(root->left) - height(root->right)) <= 1;

    return left && right && difference;
}

// ==========================================
// 5. BALANCED TREE - OPTIMIZED
// LEETCODE 110 - O(N)
// PAIR APPROACH
// ==========================================

pair<bool, int> isBalancedFast(TreeNode* root) {

    if (root == nullptr) {
        return {true, 0};
    }

    pair<bool, int> left = isBalancedFast(root->left);
    pair<bool, int> right = isBalancedFast(root->right);

    bool diff = abs(left.second - right.second) <= 1;

    bool balanced = left.first && right.first && diff;

    int h = max(left.second, right.second) + 1;

    return {balanced, h};
}

bool isBalancedOptimized(TreeNode* root) {

    return isBalancedFast(root).first;
}

// ==========================================
// 6. IDENTICAL / SAME TREE
// LEETCODE 100
// ==========================================

bool isIdentical(TreeNode* p, TreeNode* q) {

    if (p == nullptr && q == nullptr) {
        return true;
    }

    if (p == nullptr || q == nullptr) {
        return false;
    }

    if (p->val != q->val) {
        return false;
    }

    return isIdentical(p->left, q->left) &&
           isIdentical(p->right, q->right);
}

// ==========================================
// 7. SUM TREE - OPTIMIZED
// PAIR APPROACH
// ==========================================

pair<bool, int> isSumTreeFast(TreeNode* root) {

    // Empty tree
    if (root == nullptr) {
        return {true, 0};
    }

    // Leaf node
    if (root->left == nullptr && root->right == nullptr) {
        return {true, root->val};
    }

    pair<bool, int> leftAns = isSumTreeFast(root->left);
    pair<bool, int> rightAns = isSumTreeFast(root->right);

    bool left = leftAns.first;
    bool right = rightAns.first;

    bool condition =
        (root->val == leftAns.second + rightAns.second);

    bool isSum = left && right && condition;

    // Total subtree sum
    int totalSum =
        root->val + leftAns.second + rightAns.second;

    return {isSum, totalSum};
}

// ==========================================
// 8. BUILD TREE USING LEVEL ORDER
// ==========================================

TreeNode* buildTree() {

    int data;

    cout << "Enter root data (-1 for NULL): ";
    cin >> data;

    if (data == -1) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(data);

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {

        TreeNode* temp = q.front();
        q.pop();

        int leftData;

        cout << "Enter left child of " << temp->val
             << " (-1 for NULL): ";
        cin >> leftData;

        if (leftData != -1) {
            temp->left = new TreeNode(leftData);
            q.push(temp->left);
        }

        int rightData;

        cout << "Enter right child of " << temp->val
             << " (-1 for NULL): ";
        cin >> rightData;

        if (rightData != -1) {
            temp->right = new TreeNode(rightData);
            q.push(temp->right);
        }
    }

    return root;
}

// ==========================================
// 9. RUN ALL TREE TESTS
// ==========================================

void runTestCase(TreeNode* root, int testNo) {

    cout << "\n========== TEST CASE "
         << testNo << " ==========\n";

    cout << "Height: "
         << height(root) << endl;

    cout << "Diameter (Brute): "
         << diameterBrute(root) << endl;

    cout << "Diameter (Optimized): "
         << getOptimizedDiameter(root) << endl;

    cout << "Balanced (Brute): "
         << (isBalancedBrute(root) ? "true" : "false")
         << endl;

    cout << "Balanced (Optimized): "
         << (isBalancedOptimized(root) ? "true" : "false")
         << endl;

    cout << "Sum Tree: "
         << (isSumTreeFast(root).first ? "true" : "false")
         << endl;
}

// ==========================================
// 10. IDENTICAL TREE TEST
// ==========================================

void runIdenticalTest(
    TreeNode* p,
    TreeNode* q,
    int testNo
) {

    cout << "\n========== IDENTICAL TREE TEST "
         << testNo << " ==========\n";

    cout << "Are Trees Identical? "
         << (isIdentical(p, q) ? "true" : "false")
         << endl;
}

// ==========================================
// 11. MAIN FUNCTION
// ==========================================

int main() {

    // TEST CASE 1
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5

    TreeNode* root1 = new TreeNode(1);

    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);

    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);

    runTestCase(root1, 1);


    // TEST CASE 2: SINGLE NODE

    TreeNode* root2 = new TreeNode(10);

    runTestCase(root2, 2);


    // TEST CASE 3: EMPTY TREE

    TreeNode* root3 = nullptr;

    runTestCase(root3, 3);


    // TEST CASE 4: SKEWED TREE

    TreeNode* root4 = new TreeNode(1);

    root4->right = new TreeNode(2);
    root4->right->right = new TreeNode(3);
    root4->right->right->right = new TreeNode(4);

    runTestCase(root4, 4);


    // TEST CASE 5: COMPLETE BINARY TREE

    TreeNode* root5 = new TreeNode(1);

    root5->left = new TreeNode(2);
    root5->right = new TreeNode(3);

    root5->left->left = new TreeNode(4);
    root5->left->right = new TreeNode(5);

    root5->right->left = new TreeNode(6);
    root5->right->right = new TreeNode(7);

    runTestCase(root5, 5);


    // ======================================
    // IDENTICAL TREE TEST CASES
    // ======================================

    // TEST 1: Identical trees

    TreeNode* p1 = new TreeNode(1);
    p1->left = new TreeNode(2);
    p1->right = new TreeNode(3);

    TreeNode* q1 = new TreeNode(1);
    q1->left = new TreeNode(2);
    q1->right = new TreeNode(3);

    runIdenticalTest(p1, q1, 1);


    // TEST 2: Different values

    TreeNode* p2 = new TreeNode(1);
    p2->left = new TreeNode(2);

    TreeNode* q2 = new TreeNode(1);
    q2->left = new TreeNode(3);

    runIdenticalTest(p2, q2, 2);


    // TEST 3: Different structures

    TreeNode* p3 = new TreeNode(1);
    p3->left = new TreeNode(2);

    TreeNode* q3 = new TreeNode(1);
    q3->right = new TreeNode(2);

    runIdenticalTest(p3, q3, 3);


    // TEST 4: Both empty

    TreeNode* p4 = nullptr;
    TreeNode* q4 = nullptr;

    runIdenticalTest(p4, q4, 4);


    // ======================================
    // SUM TREE TEST CASE
    // ======================================

    //          26
    //         /  \
    //        10   3
    //       / \    \
    //      4   6    3

    TreeNode* sumRoot = new TreeNode(26);

    sumRoot->left = new TreeNode(10);
    sumRoot->right = new TreeNode(3);

    sumRoot->left->left = new TreeNode(4);
    sumRoot->left->right = new TreeNode(6);

    sumRoot->right->right = new TreeNode(3);

    cout << "\n========== SUM TREE TEST ==========\n";

    cout << "Is Sum Tree: "
         << (isSumTreeFast(sumRoot).first ? "true" : "false")
         << endl;


    // ======================================
    // CUSTOM TREE INPUT
    // ======================================

    cout << "\n========== CUSTOM TREE ==========\n";

    TreeNode* customRoot = buildTree();

    runTestCase(customRoot, 6);


    // ======================================
    // CUSTOM IDENTICAL TREE INPUT
    // ======================================

    cout << "\n========== CUSTOM IDENTICAL TREE ==========\n";

    cout << "\nEnter First Tree:\n";
    TreeNode* first = buildTree();

    cout << "\nEnter Second Tree:\n";
    TreeNode* second = buildTree();

    cout << "\nIdentical Result: "
         << (isIdentical(first, second) ? "true" : "false")
         << endl;


    return 0;
}
