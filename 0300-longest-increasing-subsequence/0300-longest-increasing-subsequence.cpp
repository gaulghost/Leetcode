class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i]) ans[i] = max(ans[i], ans[j] + 1);
            }
        }
        int a = 1;
        for(int i: ans) a = max(a, i);
        return a; 
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna