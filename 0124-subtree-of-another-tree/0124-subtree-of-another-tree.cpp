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
    bool verify(TreeNode* root, TreeNode* subRoot){
        if(subRoot == NULL) return root == NULL ? true : false;
        if(root == NULL || root->val != subRoot->val) return false;
        bool lft = verify(root->left, subRoot->left);
        bool rgt = verify(root->right, subRoot->right);
        return lft && rgt;
    }

    bool findStart(TreeNode* root, TreeNode* subRoot){
        if (root == NULL) return false;
        bool r = false;
        if (root->val == subRoot->val) r = verify(root, subRoot);
        bool lft = findStart(root->left, subRoot);
        bool rgt = findStart(root->right, subRoot);
        return r || lft || rgt;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return findStart(root, subRoot);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna