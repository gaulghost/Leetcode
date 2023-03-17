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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int flag = false;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i<sz; i++){
                TreeNode* temp = q.front();
                if(!temp->left) flag = true;
                if(temp->left) q.push(temp->left);
                if(flag && temp->left) return false;
                if(!temp->right) flag = true;
                if(temp->right) q.push(temp->right);
                if(flag && temp->right) return false;
                q.pop();
            }
        }
        return true;
    }
};