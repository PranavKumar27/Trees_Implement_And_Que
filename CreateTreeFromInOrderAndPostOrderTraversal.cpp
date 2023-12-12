#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Node
{
public:
    string data;
    Node* left,*right;

    Node(string d)
    {
        data = d;
        left = right = nullptr;
    }
    Node(){}
};

void print_InOrder(Node* root)
{
    if(root == NULL)
        return;

    print_InOrder(root->left);
    cout << "\t" << root->data;
    print_InOrder(root->right);
}
void print_v(vector<string>v)
{
    for(auto i:v)
    {
        cout << i << "\t";
    }
    cout << endl;
}

Node* buildTree(vector<string>inOrder,vector<string>postOrder,int& rootIdx,Node* root)
{
    cout << "-----" << __FUNCTION__ << "--------" << endl;

    if(rootIdx >= postOrder.size())
    {
        return root;
    }
    string str = postOrder[rootIdx];
    Node* tempRoot = new Node(postOrder[rootIdx]);

    if(rootIdx==0 && root == NULL)
    {
        root = tempRoot;
    }

    vector<string>::iterator itr = std::find(inOrder.begin(),inOrder.end(),str);

    if(itr!=inOrder.end())
    {
        if(inOrder.size()==1)
        {
            tempRoot->left = NULL;
            tempRoot->right = NULL;
            return tempRoot;
        }
        else
        {
            rootIdx++;
            vector<string> LeftSubtree(inOrder.begin(),itr);
            print_v(LeftSubtree);
            tempRoot->left = buildTree(LeftSubtree,postOrder,rootIdx,root);

            rootIdx++;
            if(rootIdx >= postOrder.size())
            {
                return tempRoot;
            }
            vector<string> RightSubtree(itr+1,inOrder.end());
            print_v(RightSubtree);
            tempRoot->right = buildTree(RightSubtree,postOrder,rootIdx,root);
            return tempRoot;
        }
    }
    return root;

}

int main()
{
    vector<string> inOrder{"D","B","E","A","F","C"};
    vector<string> postOrder{"A","B","D","E","C","F"};

    int rootIdx = 0;
    Node* root=nullptr;
    root = buildTree(inOrder,postOrder,rootIdx,root);
    cout << "InOrder Traversal" << endl;
    print_InOrder(root);


    return 0;
}
