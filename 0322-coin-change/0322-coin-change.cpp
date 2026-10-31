class Solution {
public:
    int countCoins(vector<int>& coins, int amt, vector<int>& dp){
        if(amt == 0) return 0;
        if(dp[amt] != -1) return dp[amt];
        int ans = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            if(coins[i] > amt) continue;
            int cur = countCoins(coins, amt-coins[i], dp);
            if(cur != INT_MAX) cur++;
            ans = min(ans, cur);
        }
        return dp[amt] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        int ans = countCoins(coins, amount, dp);
        if(ans == INT_MAX) return -1;
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna