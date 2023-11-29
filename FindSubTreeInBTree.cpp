/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)
            return false;
        // if(subRoot == NULL)
        //     return false;
        
        if(IsIdentical(root,subRoot))
        {
            return true;
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }

    bool IsIdentical(TreeNode* root,TreeNode* subRoot )
    {
        if(!root && !subRoot)
            return true;

        if(!root || !subRoot)
            return false;

        if(root->val != subRoot->val)
            return false;

        return IsIdentical(root->left,subRoot->left) &&
                IsIdentical(root->right,subRoot->right);
    }
};
