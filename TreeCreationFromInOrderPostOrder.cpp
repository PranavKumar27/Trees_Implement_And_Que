#include <iostream>
#include <map>

using namespace std;

template<typename T>
class Node
{
public:
    T data;
    Node* left,*right;

    Node(){}
    Node(T d)
    {
        data = d;
        left=right=NULL;
    }
};
template<typename T>
int search_inOrder(T in[],int s,int e,T val)
{
    int i;
    for(i=s;i<=e;i++)
    {
        if(in[i] == val)
        {
            return i;
        }
    }
    return -1;
}


template<typename T>
Node<T>* buildTree(T in[],T pre[],int s,int e,map<T,int> Mp)
{
    static int pre_idx=0;
    if(s>e)
    {
        return NULL;
    }

    T val = pre[pre_idx++];
    Node<T>* temp = new Node<T>(val);

    if(s==e)
    {
        return temp;
    }

    //int idx = search_inOrder(in,s,e,val);
    int idx = Mp[val];
    if(idx!=-1)
    {
        temp->left = buildTree(in,pre,s,idx-1,Mp);
        temp->right = buildTree(in,pre,idx+1,e,Mp);
    }
    return temp;
}

template<typename T>
void inOrder(Node<T>* root)
{
    if(root==NULL)
       return;

    inOrder(root->left);
    cout << "\t" << root->data;
    inOrder(root->right);
}

void createMapOfIndexs(char in[],int s,int e,map<char,int>& Mp)
{
    for(int i=s;i<=e;i++)
    {
        Mp[in[i]]=i;
    }
}
int main()
{
    char in[] = {'D','B','E','A','F','C'};
    char pre[] = {'A','B','D','E','C','F'};

    map<char,int> Mp;
    int sz = sizeof(in)/sizeof(char);
    createMapOfIndexs(in,0,sz-1,Mp);
    Node<char>* root = buildTree(in,pre,0,sz-1,Mp);

    cout << "InOrder Traversal:" << endl;
    inOrder(root);
    cout << endl;

    return 0;
}
