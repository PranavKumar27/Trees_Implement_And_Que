#include <iostream>
#include <vector>
#include <Map>

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

// Done in BigO(N*N)
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

// Done in BigO(N)
Node* createTree(vector<int>& parent)
{
    int n=parent.size();
    map<int,Node*> Mp;
    Node* root;
    for(int i=0;i<n;i++)
    {
        if(parent[i]==-1)
        {
            root=new Node(i);
            Mp[i] = root;
        }
        else
        {
            Node* temp = new Node(i);
            Mp[i] = temp;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(parent[i]==-1)
        {
            continue;
        }
        else
        {
            auto prnt= Mp.find(parent[i]); // parent
            if(prnt != Mp.end())
            {
                Node* tempParent = prnt->second; // parent
                auto chd= Mp.find(i); // child
                if(chd!=Mp.end())
                {
                    if(tempParent->left == NULL)
                    {
                        tempParent->left = chd->second;
                    }
                    else
                    {
                        tempParent->right = chd->second;
                    }
                }

             }

        }
    }
    return root;
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

    cout << endl;
    vector<int>parent1{1,5,5,2,2,-1,3};
    Node* root1=createTree(parent1);

    inOrder(root1);

    return 0;
}
