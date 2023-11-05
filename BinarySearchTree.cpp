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

Node* insertIntoBST(Node* root, int data)
{
    if(root == NULL)
    {
        cout << "New Node inserted: data:" << data << endl;
        return new Node(data);
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
        return root;
    }
}

Node* insertViaRecursion(Node* root, int val)
{
    if(!root)
    {
        return new Node(val);
    }

    if(root->data < val)
    {
        root->right = insertViaRecursion(root->right,val);
    }
    else if(root->data > val)
    {
        root->left = insertViaRecursion(root->left,val);
    }
    return root;
}
int main()
{
    //Iterative Approach
    Node* root = NULL;
    root = insertIntoBST(root,10);
    root = insertIntoBST(root,25);
    root = insertIntoBST(root,15);
    root = insertIntoBST(root,5);

    cout << "\nInOrder Traversal" << endl;
    inOrder(root);
    cout << endl << endl;




    // Iterative Approach
    Node* head=NULL;
    head = insertViaRecursion(head,100);
    head = insertViaRecursion(head,200);
    head = insertViaRecursion(head,300);
    head = insertViaRecursion(head,50);
    head = insertViaRecursion(head,75);


     cout << "\nInOrder Traversal" << endl;
    inOrder(head);
    cout << endl << endl;


    return 0;
}
