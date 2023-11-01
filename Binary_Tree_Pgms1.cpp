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
    cout << "Level Order Traverse Done" << endl;
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




    return 0;
}
