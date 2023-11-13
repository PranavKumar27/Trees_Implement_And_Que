#include <iostream>
#include <queue>
#include <cstring>

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
    q.push(NULL);
    int depth = -1;
    Node* temp;
    while(!q.empty())
    {
       temp=q.front();
       q.pop();

       if(temp==NULL)
       {
           depth++;
       }

       if(temp!=NULL)
       {
           if(temp->left)
           {
              q.push(temp->left);
           }
           if(temp->right)
           {
               q.push(temp->right);
           }
       }

       else if(!q.empty())
       {
           q.push(NULL);
       }
    }
    return depth;
}

int depthUsingLevelOrderTraversalAnotherTechnique(Node* root)
{
    if(root == NULL)
    {
        return -1;
    }

    int height=-1;
    queue<Node*> q;
    q.push(root);
    int sz=0;
    Node* temp;
    while(!q.empty())
    {
        sz=q.size();
        for(int i=0;i<sz;i++)
        {
            temp=q.front();
            q.pop();
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
        height++;
    }
    return height;
}

string findInOrder(Node* root,string& str)
{
    if(root == NULL)
    {
        return str;
    }
    findInOrder(root->left,str);
    str+=to_string(root->data);
    findInOrder(root->right,str);
    return str;
}
string findPostOrder(Node* root,string& str)
{
    if(root == NULL)
    {
        return str;
    }
    findPostOrder(root->left,str);
    findPostOrder(root->right,str);
    str+=to_string(root->data);
    return str;
}
string findPreOrder(Node* root,string& str)
{
    if(root == NULL)
    {
        return str;
    }
    str+=to_string(root->data);
    findPreOrder(root->left,str);
    findPreOrder(root->right,str);
    return str;
}
bool compareTwoBST(Node* root1, Node* root2)
{
    string str = "";
    string oInOrderData1 = findInOrder(root1,str);
    cout << "InOrderData1=" << oInOrderData1 << endl;

    str = "";
    string oInOrderData2 = findInOrder(root2,str);
    cout << "InOrderData2=" << oInOrderData2 << endl;

    str = "";
    string oPreOrderData1 = findPreOrder(root1,str);
    cout << "oPreOrderData1=" << oPreOrderData1 << endl;


    str = "";
    string oPreOrderData2 = findPreOrder(root2,str);
    cout << "oPreOrderData2=" << oPreOrderData2 << endl;

    str = "";
    string oPostOrderData1 = findPostOrder(root1,str);
    cout << "oPostOrderData1=" << oPostOrderData1 << endl;

    str = "";
    string oPostOrderData2 = findPostOrder(root2,str);
    cout << "oPostOrderData2=" << oPostOrderData2 << endl;


    if((oInOrderData1==oInOrderData2) && (oPreOrderData1==oPreOrderData2) && (oPostOrderData1==oPostOrderData2))
    {
        cout << "\nBoth Trees are identical" << endl;
        return true;
    }
    else
    {
        return false;
    }
}

/*
    Complexity of the above function

    Time complexity: O(N)
    Auxiliary Space: O(N), since using auxiliary ArrayList and call stack
*/

bool compareTwoTrees(Node* root1,Node* root2)
{
    if(root1==NULL && root2==NULL)
    {
        return true;
    }
    if(root1==NULL || root2==NULL)
    {
        return false;
    }
    /*
    if(root1==NULL && root2!=NULL)
    {
        return false;
    }
    */
    if(root1->data != root2->data)
    {
        return false;
    }

    bool v1=compareTwoTrees(root1->left,root2->left);

    bool v2=compareTwoTrees(root1->right,root2->right);

    return v1&v2;
}
/*
Complexity of the above Method

Time Complexity: O(min(N, M)), Where N and M are the sizes of the trees
Auxiliary Space: O(log min(N, M)), due to auxiliary stack space used by recursion calls

*/

void compareUsingPreOrder(Node* root,vector<int>& v)
{
    if(root==NULL)
    {
        return;
    }

    v.push_back(root->data);
    if(root->left)
    {
        compareUsingPreOrder(root->left,v);
    }
    if(!root->left)
    {
        v.push_back(0);
    }
    if(root->right)
    {
        compareUsingPreOrder(root->right,v);
    }
    if(!root->right)
    {
        v.push_back(0);
    }
}

/*
    Complexity of the above function
    Time complexity: O(N)+O(M)
    Auxiliary Space: O(N)+O(M) for vectors.
*/
bool compareUsingLevelOrderTraversal(Node* root1,Node* root2)
{
    if(root1 == NULL || root2== NULL)
    {
        return false;
    }
    queue<Node*> q1;
    queue<Node*> q2;
    q1.push(root1);
    q2.push(root2);

    while(!q1.empty() && !q2.empty())
    {
        Node* tmp1 = q1.front();
        Node* tmp2 = q2.front();
        q1.pop();
        q2.pop();

        if(tmp1->data != tmp2->data)
        {
            return false;
        }
        if(tmp1->left==NULL && tmp2->left!=NULL)
        {
            return false;
        }
         if(tmp1->left!=NULL && tmp2->left==NULL)
        {
            return false;
        }
        if(tmp1->right==NULL && tmp2->right!=NULL)
        {
            return false;
        }
         if(tmp1->right!=NULL && tmp2->right==NULL)
        {
            return false;
        }
        if(tmp1->left && tmp2->left)
        {
            q1.push(tmp1->left);
            q2.push(tmp2->left);
        }
        if(tmp1->right && tmp2->right)
        {
            q1.push(tmp1->right);
            q2.push(tmp2->right);
        }

    }
    return true;
}

/*
    Complexity of the above function
    Time complexity: O(N) , the time complexity will be proportional to the total number of nodes.
    Auxiliary Space: O(N), The auxiliary space complexity of the level order traversal approach is O(n), where n is the total number of nodes in both trees.

*/
int main()
{
    //Iterative Approach
    Node* root = NULL;
    root = insertIntoBST(root,2);
    root = insertIntoBST(root,1);
    root = insertIntoBST(root,3);


    Node* root1 = NULL;
    root1 = insertIntoBST(root1,1);
    root1 = insertIntoBST(root1,2);
    root1 = insertIntoBST(root1,3);



    cout << "\nInOrder Traversal of Tree 1" << endl;
    inOrder(root);
    cout << endl << endl;


    cout << "\nInOrder Traversal of Tree 2" << endl;
    inOrder(root1);
    cout << endl << endl;

    cout << "\n Trees are Equal Using compareTwoBST = " << compareTwoBST(root,root1) << endl;
    cout << "\n Trees are Equal using compareTwoTrees = " << compareTwoTrees(root,root1) << endl;

    vector<int>v1;
    vector<int>v2;

    compareUsingPreOrder(root,v1);
    compareUsingPreOrder(root1,v2);

    if(v1==v2)
    {
        cout << "Trees are equal using PreOrder" << endl;
    }
    else
    {
        cout << "Trees are Unequal using PreOrder" << endl;
    }

    bool status = compareUsingLevelOrderTraversal(root,root1);

    if(status)
    {
        cout << "Trees are equal using compareUsingLevelOrderTraversal" << endl;
    }
    else
    {
        cout << "Trees are Unequal using compareUsingLevelOrderTraversal" << endl;
    }

    cout << "Height of Binary Search Tree Using Technique 1:" << height(root) << endl;
    cout << "Height of Binary Search Tree Using Technique 2:" << findheightOfTree(root) << endl;
    cout << "Height of Binary Search Tree Using Technique 3 Level Order Traversal:" << depthUsingLevelOrderTraversal(root) << endl;
    cout << "Height of Binary Search Tree Using Technique 3 Level Order Traversal Another Technique:" << depthUsingLevelOrderTraversalAnotherTechnique(root) << endl;

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
