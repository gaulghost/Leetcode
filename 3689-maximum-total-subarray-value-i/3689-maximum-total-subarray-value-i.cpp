class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxi=nums[0], mini = nums[0];
        for(int i: nums){
            maxi = max(maxi, i);
            mini = min(mini, i);
        }
        return ((long long)(maxi-mini)*(long long)k);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna