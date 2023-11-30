#include <iostream>

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
        left = right = nullptr;
    }
};

bool IsSingleValuedTree(Node* root,int& counter)
{
    if(root==NULL)
    {
        //cout << "NuLL data" << endl;
        //counter++;
        return true;
    }

    //cout << "root->data=" << root->data << endl;


    bool leftdata = IsSingleValuedTree(root->left,counter);
    //cout << "leftdata=" << leftdata << " \t counter=" << counter << endl;
    bool rightdata = IsSingleValuedTree(root->right,counter);
    //cout << "rightdata=" << rightdata << " \t counter=" << counter << endl;

    if(leftdata == false || rightdata == false)
    {
       return false;
    }


    if(root->left && root->left->data != root->data)
        return false;

    if(root->right && root->right->data != root->data)
        return false;

    counter++;
    return true;

    /*
    if(leftdata == true && rightdata == true )
    {
        if(root->left!=NULL && root->right!=NULL)
        {
            if(root->left->data == root->data && root->right->data == root->data)
            {
                counter=counter+3;
            }
            else if(root->left->data != root->data && root->right->data != root->data && root->left->data == root->right->data)
            {
                counter=counter+2;
            }
            else if(root->left->data != root->data && root->right->data != root->data)
            {
                return false;
            }
            else if(root->left->data != root->data && root->right->data == root->data)
            {
                ++counter;
            }
            else if(root->left->data == root->data && root->right->data != root->data)
            {
                ++counter;
            }
        }
        else if(root->left!=NULL && root->right==NULL)
        {
            if(root->left->data == root->data )
            {
                ++counter;
            }
            else
                return false;
        }
        else if(root->left==NULL && root->right!=NULL)
        {
            if(root->right->data == root->data )
            {
                ++counter;
            }
            else
                return false;
        }
        return true;
    }
    */


}
int main()
{

    Node* root= new Node(5);
    root->left = new Node(4);
    root->right = new Node(5);
    root->left->left = new Node(4);
    root->left->right = new Node(4);
    root->right->left = new Node(5);


    int counter=0;

    bool b = IsSingleValuedTree(root,counter);

    cout << "IsSingleValuedTree =" << b << "\t No of Single Valued Trees =" << counter << endl;

    cout << "Hello world!" << endl;
    return 0;
}
