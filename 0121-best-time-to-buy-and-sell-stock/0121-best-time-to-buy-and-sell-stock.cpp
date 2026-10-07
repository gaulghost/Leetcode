class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=0, ans = 0;
        for(int i=0; i<prices.size(); i++){
            ans = max(ans, prices[i] - prices[buy]);
            if(prices[buy]>prices[i]){
                buy = i;
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna