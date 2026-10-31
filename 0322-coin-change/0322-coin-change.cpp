class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(int i=1; i<dp.size(); i++){
            int minval = INT_MAX;
            for(int j=0; j<coins.size(); j++){
                if(i-coins[j] < 0) continue;
                minval = min(minval, dp[i-coins[j]]==INT_MAX ? INT_MAX : dp[i-coins[j]]+1);
            }
            dp[i] = minval;
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna