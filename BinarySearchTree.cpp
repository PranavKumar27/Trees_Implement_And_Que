#include <iostream>
#include <queue>

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
                cout << "2 New temp data:" << temp->data << endl;
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

Node* findMin(Node* root)
{
    if(root == NULL)
    {
       return NULL;
    }

    Node* minNode=root;
    Node* temp=root;

    while(temp!=NULL)
    {
        if(temp->data < minNode->data)
        {
            minNode = temp;
        }
        temp=temp->left;
    }
    return minNode;
}

Node* deleteViaRecursion(Node* root, int val)
{
    if(root==NULL)
    {
        return NULL;
    }
    else
    {
        if(root->data < val)
        {
            root->right=deleteViaRecursion(root->right,val);
            return root;
        }
        else if(root->data > val)
        {
            root->left=deleteViaRecursion(root->left,val);
            return root;
        }
        else if(root->data == val)
        {
            if(root->left == NULL && root->right == NULL)
            {
                delete(root);
                return NULL;
            }
            else if(root->left != NULL && root->right == NULL)
            {
                Node* temp= root->left;
                delete(root);
                return temp;
            }
            else if(root->right != NULL && root->left == NULL)
            {
                Node* temp= root->left;
                delete(root);
                return temp;
            }
            else
            {
                cout << "Call findMin" << endl;
                Node* minTemp = findMin(root->right);
                cout << "minTemp data:" << minTemp->data << endl;
                root->data = minTemp->data;
                root->right=deleteViaRecursion(root->right,minTemp->data);
                return root;
            }
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

unsigned findMax(unsigned a,unsigned b)
{
    return(a>b)?a:b;
}

unsigned findheightOfTree(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->left == NULL && root->right == NULL)
    {
        return 0;
    }
    return findMax(findheightOfTree(root->left),findheightOfTree(root->right)) + 1;
}

int height(Node* root)
{
    if(root == NULL)
    {
        return -1;
    }
    int ldepth = height(root->left);
    int rdepth = height(root->right);

    if(ldepth > rdepth)
    {
        return ldepth+1;
    }
    else
    {
        return rdepth+1;
    }
}

int depthUsingLevelOrderTraversal(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    queue<Node*>q;
    q.push(root);
    int depth = -1;
    Node* temp;
    while(!q.empty())
    {
       temp=q.front();
       q.pop();

        cout << "\n temp->data:" << temp->data << endl;
       if(q.empty())
       {
           depth++;
           cout << "\ndepth =" << depth << endl;
       }

       if(temp->left != NULL)
       {
           q.push(temp->left);
       }
       if(temp->right != NULL)
       {
           q.push(temp->right);
       }
    }
    return depth;
}

int main()
{
    //Iterative Approach
    Node* root = NULL;
    root = insertIntoBST(root,3);
    root = insertIntoBST(root,1);
    root = insertIntoBST(root,7);
    root = insertIntoBST(root,5);
    root = insertIntoBST(root,4);



    cout << "\nInOrder Traversal" << endl;
    inOrder(root);
    cout << endl << endl;

    cout << "Height of Binary Search Tree Using Technique 1:" << height(root) << endl;
    cout << "Height of Binary Search Tree Using Technique 2:" << findheightOfTree(root) << endl;
    cout << "Height of Binary Search Tree Using Technique 3 Level Order Traversal:" << depthUsingLevelOrderTraversal(root) << endl;
    //root=deleteNode(root,15);
    //root=deleteViaRecursion(root,30);

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
