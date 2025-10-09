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
    void recur(TreeNode* root, vector<int>& p){
        if(root == NULL) return;
        if(root->left) recur(root->left, p);
        p.push_back(root->val);
        if(root->right) recur(root->right, p);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> p;
        recur(root, p);
        return p[k-1];
    }
};