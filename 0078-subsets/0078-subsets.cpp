class Solution {
public:
    void recur(vector<int>& nums, int i, vector<vector<int>>& ans){
        if(i>=nums.size()) return;
        int n = ans.size();
        for(int k=0; k<n; k++){
            vector<int> temp = ans[k];
            temp.push_back(nums[i]);
            ans.push_back(temp);
        }
        recur(nums, i+1, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans(1, vector<int>(0,0));
        recur(nums, 0, ans);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna