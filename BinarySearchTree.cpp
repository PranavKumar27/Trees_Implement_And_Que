#include <iostream>
#include <queue>
#include <stack>
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

int diameterOfABinaryTree(Node*root,int& ans)
{
    if(root==NULL)
    {
        return 0;
    }

    int lh = diameterOfABinaryTree(root->left,ans);
    int rh = diameterOfABinaryTree(root->right,ans);

    ans = max(ans,1+lh+rh);

    return 1+max(lh,rh);
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

int height_Of_SubTree(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }

    int lh=height_Of_SubTree(root->left);
    int rh=height_Of_SubTree(root->right);

    return 1+max(lh,rh);
}

bool CheckForTreeAsHeightBalanced(Node* root)
{
    if(root == NULL)
    {
        return true;
    }

    int lh = height_Of_SubTree(root->left);
    int rh = height_Of_SubTree(root->right);

    //cout << "lh=" << lh << "  rh=" << rh << endl;
    if(abs(lh-rh)>=1 && CheckForTreeAsHeightBalanced(root->left) && CheckForTreeAsHeightBalanced(root->right))
    {
        return true;
    }
    return false;

}

void InOrderQueue(Node* root,queue<Node*>&q)
{
    if(root == NULL)
    {
        return;
    }
    InOrderQueue(root->left,q);
    q.push(root);
    cout << "data=\t" << root->data << endl;
    InOrderQueue(root->right,q);


}
void printCDLL(Node* head)
{
    Node* temp=head;
    while(temp->right!=head)
    {
        cout << temp->data << endl;
        temp = temp->right;
    }
    cout << temp->data << endl;
}
Node* ConvertBSTAsCDLL(Node* root)
{
    queue<Node*>q;

    InOrderQueue(root,q);

    Node*head = NULL;
    Node* temp;
    Node* tempHead = head;
    Node* newNodeZZ = NULL;
    Node* prevtempHead = NULL;

    cout << "Queue sz= " << q.size() << endl;
    while(!q.empty())
    {
        temp = q.front();
        cout << "temp data =" << temp->data << endl;
        q.pop();

        tempHead = head;
        newNodeZZ = new Node(temp->data);

        prevtempHead = NULL;
        while(tempHead != NULL)
        {
            prevtempHead = tempHead;
            tempHead = tempHead->right;
        }
        if(prevtempHead!=NULL)
            prevtempHead->right = newNodeZZ;
        if(head == NULL)
        {
            head = newNodeZZ;
            cout << "Head data =" << head->data << endl;
        }
    }

    cout << "NewNode ==" << newNodeZZ->data << endl;
    if(newNodeZZ!=NULL)
        newNodeZZ->right = head;
    printCDLL(head);
    return head;


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

void convertIntoMirrorImage(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    convertIntoMirrorImage(root->left);
    convertIntoMirrorImage(root->right);

    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

Node* convertIntoMirrorImageUsingLevelOrder(Node* root)
{
    if(root == NULL)
    {
        return NULL;
    }
    queue<Node*> q;
    q.push(root);
    Node* tmpPtr;

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        tmpPtr = temp->left;
        temp->left = temp->right;
        temp->right = tmpPtr;

        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
    }
    return root;
}

bool checkIfTreeIsMirror(Node* root1,Node* root2)
{
    if(root1 == NULL && root2 == NULL)
    {
        return true;
    }

    if(root1 && root2 && root1->data ==  root2->data)
    {
        return checkIfTreeIsMirror(root1->left,root2->right) && checkIfTreeIsMirror(root1->right,root2->left);
    }

    return false;
}


bool checkIfTreeIsSymetric(Node* root)
{
    if(root!=NULL)
    {
        return checkIfTreeIsMirror(root,root);
    }
    else
    {
        return false;
    }
}


bool checkIfTreeHasSymetricUsingStack(Node* root)
{

    if(root == NULL)
    {
        return true;
    }

    stack<Node*>s1;
    stack<Node*>s2;
    s1.push(root);
    s2.push(root);
    Node* temp1=NULL;
    Node* temp2=NULL;

    while(!s1.empty() && !s2.empty())
    {
        temp1 = s1.top();
        s1.pop();
        temp2 = s2.top();
        s2.pop();

        if(temp1==NULL && temp2==NULL)
        {
            continue;
        }
        if(temp1==NULL || temp2==NULL)
        {
            return false;
        }
        if(temp1->data != temp2->data)
        {
            return false;
        }
        s1.push(temp1->left);
        s2.push(temp2->right);
        s1.push(temp1->right);
        s2.push(temp2->left);
    }
    return true;

}

bool checkIfTreeHasSymetricUsingQueue(Node* root)
{
    if(root == NULL)
    {
        return false;
    }

    queue<Node*>q;
    q.push(root);
    q.push(root);

    while(!q.empty())
    {
        Node* temp1=q.front();
        q.pop();
        Node* temp2=q.front();
        q.pop();

        if(temp1 == NULL && temp2 == NULL)
        {
            continue;
        }
        if(temp1 == NULL || temp2 == NULL)
        {
            return false;
        }
        if(temp1->data != temp2->data)
        {
            return false;
        }

        q.push(temp1->left);
        q.push(temp2->right);
        q.push(temp1->right);
        q.push(temp2->left);
    }
    return true;
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
    /*root = insertIntoBST(root,7);
    root = insertIntoBST(root,5);
    root = insertIntoBST(root,5);*/
    //root = insertIntoBST(root,1);

    root = new Node(7);
    root->left = new Node(5);
    root->left->left = new Node(12);
    root->left->right = new Node(15);
    root->left->left->left = new Node(9);
    root->left->right->right = new Node(29);
    root->left->left->left->right = new Node(25);
    root->left->right->right->left = new Node(16);

    Node* root1 = NULL;
    root1 = insertIntoBST(root1,3);
    root1 = insertIntoBST(root1,5);
    root1 = insertIntoBST(root1,8);
    /*root1 = insertIntoBST(root1,9);
    root1 = insertIntoBST(root1,4);
    root1 = insertIntoBST(root1,3);
    root1 = insertIntoBST(root1,5);
    root1 = insertIntoBST(root1,2);
*/
    cout << "Check If Tree is height Balanced :" << CheckForTreeAsHeightBalanced(root1) << endl;


    cout << "\nInOrder Traversal of Tree 1" << endl;
    inOrder(root);
    cout << endl << endl;

/*
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

    cout << "\nBefore Mirror Image InOrder Traversal" << endl;
    inOrder(root);
    cout << endl << endl;


    cout << "\n Convert into Mirror Image" << endl;
    convertIntoMirrorImage(root);

    cout << "\nAfter Mirror Image InOrder Traversal" << endl;
    inOrder(root);
    cout << endl << endl;

    root=convertIntoMirrorImageUsingLevelOrder(root);

    cout << "\nAgain After Mirror Image InOrder Traversal" << endl;
    inOrder(root);
    cout << endl << endl;

    cout << "\n Check if Tree is symetric:" << checkIfTreeIsSymetric(root) << endl;

    cout << "\n Check if Tree is symetric Using Stacks:" << checkIfTreeHasSymetricUsingStack(root) << endl;

    cout << "\n Check if Tree is symetric Using Queue:" << checkIfTreeHasSymetricUsingQueue(root) << endl;

    int diameter=0;
    diameterOfABinaryTree(root,diameter);
    cout << "\n Diameter of a Tree :" << diameter  << endl;
*/
    Node*head = ConvertBSTAsCDLL(root);
    cout << "Convert BST to CDLL:" << endl;
    printCDLL(head);

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
