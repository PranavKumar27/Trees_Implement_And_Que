#include <iostream>
#include <vector>
#include <climits>

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
        left = right = NULL;
    }
};

void inOrder(Node* root)
{
    if(root==NULL)
        return;
    inOrder(root->left);
    cout << "\t" << root->data;
    inOrder(root->right);
}

Node* buildTreeFromPreOrder(vector<int> pre,int preStart,int preEnd)
{
     int sz = pre.size();

     if(preStart>=preEnd || sz == 0)
     {
         return NULL;
     }

     int val = pre[preStart];
     int idx=-1;
     int i = preStart+1;
     while(true && i<sz)
     {
         if(val<pre[i])
         {
             idx = i;
             break;
         }
         i++;
     }
     Node* temp = new Node(val);
     if(idx == -1) // Cannot find value Larger than root. Left Sqewed Tree Here
     {
         vector<int>leftTree{pre.begin()+1,pre.end()};
         temp->left = buildTreeFromPreOrder(leftTree,0,leftTree.size());
     }
     else
     {
         vector<int>leftTree{pre.begin()+1,pre.begin()+idx};
         temp->left = buildTreeFromPreOrder(leftTree,0,leftTree.size());
         if(idx<sz)
         {
             vector<int>rightTree{pre.begin()+idx,pre.end()};
             temp->right = buildTreeFromPreOrder(rightTree,0,rightTree.size());
         }
     }
     return temp;
}

int main()
{
    vector<int> PreOrder{10,5,1,7,40,50};

    Node* root = buildTreeFromPreOrder(PreOrder,0,PreOrder.size());

    inOrder(root);
    cout << endl;
    return 0;
}


