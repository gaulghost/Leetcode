class Solution {
public:
    int minCoins(vector<int>& coins, int amt, vector<int>& dp){
        if(amt == 0) return 0;
        if(dp[amt] != -1) return dp[amt];
        int ans = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            if(coins[i] <= amt) {
                int k = minCoins(coins, amt-coins[i], dp);
                ans = min(ans, k==INT_MAX ? k : 1+k);
            }
        }
        return dp[amt] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        int ans = minCoins(coins, amount, dp);
        if(ans == INT_MAX) return -1;
        return ans;
    }
};