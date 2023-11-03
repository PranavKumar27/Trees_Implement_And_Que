#include <iostream>
#include <queue>

using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left=right=NULL;
    }
};

Node* createNode(int data)
{
    Node *newNode = new Node(data);

    if( newNode == NULL )
    {
        cout << "Ran Into Memory Issue Terminating Program" << endl;
        return NULL;
    }
    else
    {
        cout << "Node with value:" << data << " created successfully" << endl;
        return newNode;
    }
}

Node* insertNode(Node* root, int newVal)
{
    //cout << "Inside insertNode" << endl;

    if(root == NULL)
    {
        createNode(newVal);
        //cout << "Root is NULL" << endl;
        return NULL;
    }
    queue<Node*>q;
    q.push(root);
    //cout << "Root is Not NULL, Pushed to Queue" << endl;


    while(!q.empty())
    {
        Node* val = q.front();
        q.pop();
        Node* left_data = val->left;
        if(left_data==NULL)
        {
            Node* newNode = createNode(newVal);
            val->left = newNode;
            //cout << "New Node Inserted " << newVal << endl;
            break;
        }
        else
        {
            q.push(left_data);
            //cout << "Left Node Pushed in Queue" << left_data->data << endl;
        }

        Node* right_data = val->right;
        if(right_data==NULL)
        {
            Node* newNode = createNode(newVal);
            val->right = newNode;
            //cout << "New Node Inserted " << newVal << endl;
            break;
        }
        else
        {
            q.push(right_data);
            //cout << "Right Node Pushed in Queue" << right_data->data << endl;
        }
    }
    return root;
}

void levelOrderTraversal(Node* root)
{
    if(root == NULL)
    {
        return;
    }

    queue<Node*>q;
    q.push(root);

    while(!q.empty())
    {
        Node* val = q.front();
        q.pop();
        cout << val->data << "\t";
        Node* left_data = val->left;
        if(left_data!=NULL)
        {
            q.push(left_data);
        }
        Node* right_data = val->right;
        if(right_data!=NULL)
        {
            q.push(right_data);
        }

        //cout<< "ReCheck Q if empty" << endl;
        //cout << "Is Q empty" << q.empty() << endl;
    }
    cout << "\n Level Order Traverse Done" << endl;
    return;
}

void inOrderTraversal(Node *root)
{

    if(root == NULL)
    {
        return;
    }

    Node* left_Ptr = root->left;
    inOrderTraversal(left_Ptr);

    cout << root->data << "\t";

    Node* right_Ptr = root->right;
    inOrderTraversal(right_Ptr);
}

void deleteRightMostNode(Node* root, Node* NodeToDelete)
{
    queue<Node*>q;
    q.push(root);

    Node* temp=NULL;

    while(!q.empty())
    {
        temp=q.front();
        q.pop();

        if(temp==NodeToDelete)
        {
            temp=NULL;
            delete(temp);
            return;
        }
        if(temp->left!=NULL)
        {
            if(temp->left == NodeToDelete)
            {
                temp->left=NULL;
                delete temp->left;
                return;
            }
            else
            {
                q.push(temp->left);
            }
        }
        if(temp->right!=NULL)
        {
            if(temp->right == NodeToDelete)
            {
                temp->right = NULL;
                levelOrderTraversal(root);
                delete(temp->right);
                return;
            }
            else
            {
                q.push(temp->right);
            }
        }
    }
}

void deleteNode(Node *root,int eleToDel)
{
    if(root == NULL)
    {
        return;
    }

    if(root->left == NULL && root->right == NULL)
    {
        if(root->data != eleToDel)
        {
            return;
        }
    }

    queue<Node*>q;
    q.push(root);
    Node* keyNode=NULL;
    Node* temp=NULL;
    Node* last=NULL;

    while(!q.empty())
    {
       temp=q.front();
       q.pop();

       if(temp->data == eleToDel)
       {
           keyNode = temp;
       }
       if(temp->left!=NULL)
       {
           last = temp;
           q.push(temp->left);
       }

       if(temp->right!=NULL)
       {
           last = temp;
           q.push(temp->right);
       }
    }

    if( keyNode != NULL )
    {
        cout << "KeyNode->data:" << keyNode->data << endl;
        cout << "temp->data:" << temp->data << endl;
        int dataToReplace = temp->data;
        keyNode->data = dataToReplace;
        //deleteRightMostNode(root,temp); // temp is the rightMost Node;
        if(last->right == temp)
        {
            last->right = NULL;
        }
        else
        {
            last->right = NULL;
        }
        delete(temp);
        cout << "KeyNode:" << keyNode << endl;

    }

}



int main()
{
    Node* root = createNode(10);
    root->left = createNode(15);
    root->right = createNode(20);

    cout << "Level Order Traversal Data \t";
    levelOrderTraversal(root);
    cout << "\n\n";

    insertNode(root,25);
    insertNode(root,30);
    insertNode(root,45);
    insertNode(root,50);

    cout << "Level Order Traversal Data \t";
    levelOrderTraversal(root);
    cout << "\n\n";

    cout << "IN-Order Traversal Data \t";
    inOrderTraversal(root);
    cout << "\n\n";

    int n=50;
    deleteNode(root,n);
    cout << "Level Order Traversal Data After Deleting" << n << endl;
    levelOrderTraversal(root);
    cout << "\n\n";

    /*
    n=10;
    deleteNode(root,n);
    cout << "Level Order Traversal Data After Deleting " << n << endl;
    levelOrderTraversal(root);
    cout << "\n\n";

    */
    return 0;
}
