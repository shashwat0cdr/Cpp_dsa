// stack implemnation using linked list

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};


class Stack
{
private:
    Node *top;
public:

    Stack(){
        top = NULL;
    }


    // push
    void push(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }
    // pop
    int pop()
    {
        if (top == NULL)
        {
            cout << "Stack underflow" << endl;
            return -1;
        }

        Node *temp = top;
        int ans = temp->data;

        top = top->next;
        delete temp;

        return ans;
    }

    int peek()
    {
        if (top == NULL)
        {
            cout << "stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty(){
        return top == NULL;
    }
};


int main(){

    Stack st;
    st.push(10);
    st.push(40);
    st.push(50);
    st.push(60);

    cout << "Top element: " << st.peek() << endl;

    // POP
    cout << "Popped: " << st.pop() << endl;
    cout << "Popped: " << st.pop() << endl;

    cout << "Top element: " << st.peek() << endl;

    cout << "Popped: " << st.pop() << endl;
    cout << "Popped: " << st.pop() << endl;

    // Underflow
    st.pop();

    return 0;

}