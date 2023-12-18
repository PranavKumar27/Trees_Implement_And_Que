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
        left = right =nullptr;
    }
};

bool IsPresent(Node* root,int n)
{
    if(root == nullptr)
        return false;
    if( root->data == n ||
       IsPresent(root->left,n) ||
       IsPresent(root->right,n) )
    {
        return true;
    }
    return false;
}

Node* findLCA(Node* root,int n1,int n2)
{
    if(root == NULL)
        return nullptr;

    if( root->data == n1 ||
       root->data == n2 )
    {
        return root;
    }
    Node* rootleft = findLCA(root->left,n1,n2);
    Node* rootright = findLCA(root->right,n1,n2);

    if( rootleft && rootright )
        return root;

    return (root->left)?root->left:root->right;
}

int findDistanceFromRoot(Node* root,int n)
{
    if(root==nullptr)
        return -1;

    queue<Node*>q;
    q.push(root);
    bool status = false;
    int dist = 0;
    while( !q.empty() )
    {
        int sz = q.size();

        for(int i=0;i<sz;i++)
        {
            Node* temp = q.front();
            q.pop();

            if(temp->data == n)
            {
                return dist;
            }
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
        dist = dist+1;

    }
    if(status)
        return dist;
    else
        return -2;
}
int main()
{

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(6);

    int n1 = 3;
    int n2 = 5;

    if(IsPresent(root,n1) && IsPresent(root,n2))
    {
        Node* res = findLCA(root,n1,n2);
        if(res)
        {
            cout << "Least Common Ancestor of (" << n1 << "," << n2 << ")= \t" << res->data << endl;
            int d1,d2,dl;
            d1 = findDistanceFromRoot(root,n1);
            d2 = findDistanceFromRoot(root,n2);
            dl = findDistanceFromRoot(root,res->data);
            //cout << "Distance are d1=" << d1 << "\td2=" << d2 << "\tdl=" << dl << endl;
            int distOfNodes = d1+d2 - 2*dl;
            cout << "Distance between Nodes " << n1 << " and " << n2 << "= \t" << distOfNodes << endl;
        }
        else
            cout << "Res is NULL" << endl;
    }
    else
    {
         cout << "Least Common Ancestor of (" << n1 << "," << n2 << ")= \t Undefined as Node not found" << endl;
    }


    return 0;
}
