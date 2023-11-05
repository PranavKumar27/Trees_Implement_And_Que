#include <iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(){}
    Node(int val)
    {
        data =  val;
        left = right = NULL;
    }
};

void inOrder( Node* root )
{
    if(root==NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << "\t";
    inOrder(root->right);
}

void insertIntoBST(Node* root, int data)
{
    if(root == NULL)
    {
        Node* newNode = new Node(data);
        root = newNode;
        cout << "New Node inserted: data:" << root->data << " root:" << root << endl;
        return;
    }
    else
    {
        Node* temp = root;
        Node* prevTemp = NULL;
        while(temp!=NULL)
        {
            if( temp ->data < data)
            {
                prevTemp = temp;
                temp = temp->right;
            }
            else if( temp->data > data )
            {
                prevTemp = temp;
                temp = temp->left;
            }
        }
        if( temp==NULL && prevTemp!=NULL )
        {
            if( prevTemp->data < data )
            {
                prevTemp->right = new Node(data);
                cout << "\nNew Node date:" << data << " Inserted to right of " << prevTemp->data << endl;
            }
            else
            {
                prevTemp->left = new Node(data);
                cout << "\nNew Node date:" << data << " Inserted to left of " << prevTemp->data << endl;;
            }
        }
        return;
    }
}

int main()
{
    //Node* root = NULL;
    //insertIntoBST(root,10);
    Node * root = new Node(10);

    insertIntoBST(root,25);
    insertIntoBST(root,15);
    insertIntoBST(root,5);

    cout << "\nInOrder Traversal" << endl;
    inOrder(root);
    cout << endl << endl;

    return 0;
}
