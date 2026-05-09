class NumArray {
public:
    NumArray(vector<int>& nums) {
        // Initialize a prefix sum array to store cumulative sums
        prefix_sum.resize(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        // Calculate the sum of the given range using the prefix sum array
        return prefix_sum[right + 1] - prefix_sum[left];
    }
private:
    vector<int> prefix_sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna