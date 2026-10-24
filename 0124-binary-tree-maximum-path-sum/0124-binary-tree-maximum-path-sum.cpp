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
    int maxSum = -1000;

    int recur(TreeNode* root) {
        if(root == NULL) return 0;
        int lft = recur(root->left);
        int rgt = recur(root->right);
        int val = max(lft + root->val, max(rgt + root->val, root->val));
        maxSum = max(maxSum, max(val, root->val + lft + rgt));
        return val;
    }

    int maxPathSum(TreeNode* root) {
        recur(root);
        return maxSum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna