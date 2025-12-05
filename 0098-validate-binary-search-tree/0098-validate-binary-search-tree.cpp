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
    bool check(TreeNode* root, long long int low, long long int high){
        if(root==NULL) return true;
        if(root->val >= high || root->val<=low) return false;
        return check(root->left,low,root->val) && check(root->right,root->val,high);
    }
    
    bool isValidBST(TreeNode* root) {
        return check(root,-1*pow(2,31)-1,pow(2,31));
    }
};