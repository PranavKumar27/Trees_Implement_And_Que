#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node* left,*right;
    Node(){}
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

bool search_BTree(Node* root,Node* temp,int key)
{
    if(temp == nullptr || root == nullptr)
        return false;

    Node* curNode = root;
    bool flag = false;

    while(curNode!=NULL && flag == false)
    {
        if(curNode!=temp && curNode->data == key)
        {
            flag = true;
            cout << "Found A Pair " << curNode->data << "," << temp->data << endl;
            return true;
        }
        if(curNode->data < key)
            curNode = curNode->right;
        else
            curNode = curNode->left;
    }
    return false;
}

bool checkIfSomePairExists(Node* root,Node* temp,int iSum)
{
    if(temp == nullptr)
        return false;

    return ( search_BTree(root,temp,iSum-temp->data)
            || checkIfSomePairExists(root,temp->left,iSum)
            || checkIfSomePairExists(root,temp->right,iSum) );
}

int main()
{
    Node* root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);

    root->left->left = new Node(8);
    root->left->right = new Node(12);

    root->right->left = new Node(16);
    root->right->right = new Node(25);

    bool ans = checkIfSomePairExists(root,root,30);

    cout << "Result =" << ans << endl;
    return 0;
}
