class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, false);

        // Step 2: base case
        dp[n - 1] = true;

        // Step 3: fill RIGHT TO LEFT (since dp[i] depends on dp[i+j])
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] == 0) { // stuck here
                dp[i] = false;
                continue;
            }
            for (int j = 1; j <= nums[i]; j++) {
                if (i + j >= n - 1 || dp[i + j]) { // can reach end
                    dp[i] = true;
                    break; // ← small optimization: stop early
                }
            }
        }

        return dp[0]; // can we reach end FROM index 0?
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna