#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int v)
    {
        data = v;
        left = right = NULL;
    }

};
void inOrder(Node* root,vector<int>& v)
{
    if(!root)
        return;
    inOrder(root->left,v);
    v.push_back(root->data);
    inOrder(root->right,v);
}

int main()
{
    Node* root;
    root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(25);

    root->left->left = new Node(5);
    root->left->right = new Node(12);

    root->right->left = new Node(20);
    root->right->right = new Node(45);

    vector<int> v;
    inOrder(root,v);

    cout << "Inorder Traversal\t" << endl;

    for(auto i:v)
    {
        cout << i << "\t";
    }
    cout << endl;

    // Find Inorder Successor
    int inorderSuccessor = 45;
    vector<int>::iterator itr;
    itr = find(v.begin(),v.end(),inorderSuccessor);
    if(itr!=v.end())
    {
        // Found
        if(itr+1 == v.end())
        {
            cout << "NULL" << endl;
        }
        else
        {
            cout << "\t" << *(itr+1) << endl;
        }

    }
    else
    {
        // Not Found
        cout << "Data Not Found" << endl;
    }


    cout << "Hello world!" << endl;
    return 0;
}


// Approach 2

 void inOrder(Node* root,vector<Node*>& v)
    {
        if(!root)
            return;
        inOrder(root->left,v);
        v.push_back(root);
        inOrder(root->right,v);
    }
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        vector<Node*> v;
        inOrder(root,v);
    
        //cout << "Inorder Traversal\t" << endl;
    
        // for(auto i:v)
        // {
        //     cout << i << "\t";
        // }
        // cout << endl;
    
        Node* inorderSuccessor;
        // Find Inorder Successor
        if(x!=NULL)
            inorderSuccessor = x;
        else
            return NULL;
            
        vector<Node*>::iterator itr;
        itr = find(v.begin(),v.end(),inorderSuccessor);
        if(itr!=v.end())
        {
            // Found
            if(itr+1 == v.end())
            {
                return NULL;
            }
            else
            {
                //cout << "\t" << ((itr+1)->data) << endl;
                Node*res = *(itr+1);
                return res;
            }
    
        }
        else
        {
            // Not Found
            cout << "Data Not Found" << endl;
        }

    }
    
