// binary tree construction

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildtree(node *root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    root = new node(data);
    cout << "Enter data for inserting in left: " << data << endl;
    root->left = buildtree(root->left);
    cout << "Enter data for inserting in right: " << data << endl;
    root->right = buildtree(root->right);
    return root;
}

void levelOrderTravesal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();

        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void reverseLevelTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<node *> q;
    stack<node *> s;

    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        s.push(temp);

        if (temp->right)
        {
            q.push(temp->right);
        }
        if (temp->left)
        {
            q.push(temp->left);
        }

        while (!s.empty())
        {
            cout << s.top()->data << " ";
            s.pop();
        }
    }
}

void inorder(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 19 -1 -1

void buildfromLevelOrder(node *&root)
{
    queue<node *> q;
    cout << " Enter data for root" << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        // left child
        cout << "enter data for left node: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        // right child
        cout << "enter data for right data: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}

int main()
{

    node *root = NULL;
    buildfromLevelOrder(root);

    // root = buildtree(root);
    // // 1 3 5 7 -1 11 -1 -1 5 17 -1 -1 19 -1 -1
    // cout << "Printing the level order of traversal" << endl;
    levelOrderTravesal(root);

    // cout << "inorder traversal: ";
    // inorder(root);
    //  cout << endl;
    cout << "preorder traversal: ";
    preorder(root);
    cout << endl;
    cout << "Postorder Travesal: ";
    postorder(root);

    return 0;
}
