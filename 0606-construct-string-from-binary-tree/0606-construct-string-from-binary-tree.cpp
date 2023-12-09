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
    string dfsTree(TreeNode* root){
        if(root == NULL) return "";
        string ans = to_string(root->val);
        if(root->left) ans += "(" + dfsTree(root->left) + ")";
        if(root->right) {
            if(!root->left) ans += "()(" + dfsTree(root->right) + ")";
            else ans += "("+ dfsTree(root->right) + ")";
        }
        return ans;
    }
    
    string tree2str(TreeNode* root) {
        string ans = dfsTree(root);
        return ans;
    }
};