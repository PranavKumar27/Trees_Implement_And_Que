// Traverse the binary tree from root -> root's left  -> then All Leaf Nodes -> then all the right nodes from bottom to the top

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node* left,*right;

    Node(int val)
    {
        data = val;
        left=right=nullptr;
    }
};

void AllLeftNodes(Node* root,vector<int> &v)
{
    if(root==nullptr)
        return;

    Node* temp=root;
    if(temp->left!=nullptr)
    {
        v.push_back(temp->data);
        AllLeftNodes(temp->left,v);
    }
    else if(temp->right!=nullptr)
    {
        v.push_back(temp->data);
        AllLeftNodes(temp->right,v);
    }
}

void AllRightNodes(Node* root,vector<int> &v)
{
    if(root==nullptr)
        return;

    if(root->right)
    {
        AllRightNodes(root->right,v);
        v.push_back(root->data);
    }
    else if(root->left)
    {
        AllRightNodes(root->left,v);
        v.push_back(root->data);
    }
}

void AllLeafNodes(Node* root,vector<int> &v)
{
    if(root==nullptr)
        return;

    AllLeafNodes(root->left,v);
    if(root->left == nullptr && root->right == nullptr)
        v.push_back(root->data);
    AllLeafNodes(root->right,v);
}


    vector <int> boundary(Node *root)
    {
        //Your code here
        
    
    vector<int> res;
    if(root==nullptr)
        return res;
    else
        res.push_back(root->data);
        
        

    AllLeftNodes(root->left,res);
    
    AllLeafNodes(root->left,res);
    AllLeafNodes(root->right,res);
    
    AllRightNodes(root->right,res);
      
    return res;
    }

void print_v(vector<int>v)
{
    for(auto i:v)
    {
        cout << i << "\t";
    }
    cout << endl;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->left->left->left = new Node(11);
    root->right->left->left = new Node(7);
    root->right->right->left = new Node(13);
    root->right->right->right = new Node(9);


    vector<int> res = boundary(root);
    print_v(res);

    

    return 0;
}
