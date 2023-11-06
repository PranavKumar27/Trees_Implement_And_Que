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

Node* deleteNode(Node* root, int val)
{
    //Case 1: If leaf Node is to be deleted- Delete directly

    //Case 2: If a node which has either only left child or only right child to be deleted,
    //then replace node (To be Deleted) data with left or right child node data

    //Case 3:If a node which is to be deleted has both left and right child,
    //then replace node (To be deleted) data with the next/immedidate inroder traversal
    //node data and delete the inroder traversal node

    //Case 1 Scenario
    Node* temp=root;
    Node* prevTemp = temp;
    while(temp!=NULL)
    {
        if(temp->data == val)
        {
            if(temp->left == NULL && temp->right == NULL)
            {
                // Case 1
                if(prevTemp->left->data == val)
                {
                    prevTemp->left = NULL;
                    delete(temp);
                    return root;
                }
                else
                {
                    prevTemp->right = NULL;
                    delete(temp);
                    return root;
                }

            }
            // Case 2
            if(temp->left != NULL && temp->right == NULL)
            {
                temp->data=temp->left->data;
                delete(temp->left);
                temp->left = NULL;
                return root;
            }
            else if(temp->left == NULL && temp->right != NULL)
            {
                temp->data=temp->right->data;
                delete(temp->right);
                temp->right = NULL;
                return root;
            }

            //Case 3
            else if(temp->left != NULL && temp->right != NULL)
            {
                cout << "New Temp data Before =" << temp->data << endl;
                Node* prev = temp;
                Node* newTemp = temp->right;
                temp->data = newTemp->data;
                cout << "New Temp data After=" << temp->data << endl;

                while(newTemp->right != NULL)
                {
                    prev = newTemp;
                    newTemp->data = newTemp->right->data;
                    cout << "New newTemp data:" << newTemp->data << endl;
                    newTemp = newTemp->right;
                }
                if(newTemp->right == NULL)
                {
                    delete(newTemp);
                    prev->right = NULL;
                }
                return root;
            }
        }
        else if(temp->data < val)
        {
            prevTemp = temp;
            Node* prevNode = temp;
            temp = temp->right;

        }
        else
        {
            prevTemp = temp;
            Node* prevNode = temp;
            temp = temp->left;

        }
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
    root = insertIntoBST(root,11);
    root = insertIntoBST(root,19);
    root = insertIntoBST(root,17);
    root = insertIntoBST(root,18);
    root = insertIntoBST(root,20);

    cout << "\nInOrder Traversal" << endl;
    inOrder(root);
    cout << endl << endl;


    root=deleteNode(root,15);

    cout << "\nInOrder Traversal" << endl;
    inOrder(root);
    cout << endl << endl;

    /*
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
    */

    return 0;
}
