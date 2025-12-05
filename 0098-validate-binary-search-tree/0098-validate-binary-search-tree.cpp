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
    bool checkBST(TreeNode* root, int maxv, int minv){
        if (root == NULL) return true;
        if(root->val>maxv || root->val<minv) 
            return false;
        return checkBST(root->left, root->val, minv) && checkBST(root->right, maxv, root->val);
    }

    bool isValidBST(TreeNode* root) {
        return checkBST(root, INT_MAX, INT_MIN);
    }
};