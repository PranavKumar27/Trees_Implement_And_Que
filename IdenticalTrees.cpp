// Technique 1: Using Level Order Traversal

bool isIdentical(Node *r1, Node *r2)
    {
        queue<Node*> q1;
        queue<Node*> q2;
        
        if(r1 == NULL && r2 == NULL)
           return true;
           
        if(r1 == NULL && r2 != NULL)
           return false;
           
        if(r1 != NULL && r2 == NULL)
           return false;
          
          q1.push(r1);
          q2.push(r2);
        while(!q1.empty() && !q2.empty())
        {
            Node* temp1 = q1.front();
            q1.pop();
            Node* temp2 = q2.front();
            q2.pop();
            
           
            if(temp1->data != temp2->data)
            {
                return false;
            }
                
                
            if(temp1->left)
                q1.push(temp1->left);
            if(temp2->left)
                q2.push(temp2->left);
            
            if(temp1->right)
                q1.push(temp1->right);
            if(temp2->right)
                q2.push(temp2->right);
        }
        
        if(q1.empty()&& q2.empty())
            return true;
        else
            return false;
    }

// Technique 2: Using Recursion
bool isIdentical(Node *t1, Node *t2)
    {
        if(t1==NULL && t2 == NULL)
            return true;
        if(t1==NULL || t2 ==NULL)
            return false;
            
        if(t1->data != t2->data)
            return false;
            
        bool left = isIdentical(t1->left,t2->left);
        bool right = isIdentical(t1->right,t2->right);
        
        return left&&right;
    }

// Technique 3: Using All Types of Traversal InOrder,PreOrder and PostOrder
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
    string str = ""; // Can use Vector instead
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


// Technique 4: Using PreOrder

void preOrder(Node* root,vector<int>& v)
{
    if(root == NULL)
        return;

    v.push_back(root->data);
    if(root->left)
        preOrder(root->left,v);
    else
        v.push_back(0);

    if(root->right)
        preOrder(root->right,v);
    else
        v.push_back(0);
}

bool isIdentical(Node* t1,Node* t2)
{
    vector<int> u,v;
    preOrder(t1,u);
    preOrder(t2,v);
    return u==v;  
}



