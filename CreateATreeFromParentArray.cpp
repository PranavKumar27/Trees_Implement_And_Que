#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* left,*right;

    Node()
    {
        data = -100;
        left=right=nullptr;
    }
    Node(int d)
    {
        data = d;
        left=right=nullptr;
    }
};

void createNode(int parent[],int i,Node* created[],Node** root)
{
    if(created[i]!=NULL)
    {
        return;
    }

    created[i] = new Node(i);

    if(parent[i] == -1)
    {
        *root = created[i];
        return;
    }


    if(created[parent[i]] == NULL)
        createNode(parent,parent[i],created,root);



    Node* p = created[parent[i]];
    if(p->left == NULL)
        p->left = created[i];
    else
        p->right = created[i];


}


void inOrder(Node* root)
{
    //cout << "root=" << root << endl;
    if(root==nullptr)
        return;

    inOrder(root->left);
    cout << root->data << "\t";
    inOrder(root->right);
}
int main()
{
    int parent[7]={1,5,5,2,2,-1,3};

    Node* created[7];
    for(int i=0;i<7;i++)
    {
        created[i] = nullptr;
    }
    Node* root=NULL;
    for(int i=0;i<7;i++)
    {
        createNode(parent,i,created,&root);
    }

    inOrder(root);


    return 0;
}
