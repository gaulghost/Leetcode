class Solution {
public:
    void recur(int i, vector<int> nums, vector<vector<int>>& ans){
        if(i == nums.size() - 1){
            ans.push_back(nums);
            return;
        }
        for(int k=0; k<nums.size()-i; k++){
            swap(nums[i], nums[k+i]);
            recur(i+1, nums, ans);
            swap(nums[i], nums[k+i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recur(0, nums, ans);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna