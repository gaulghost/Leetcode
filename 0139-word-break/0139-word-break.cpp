class Solution {
public:
    bool wordCheck(string s, int i, vector<string>& w, vector<int>& dp){
        if (i>=s.size()) return true;
        if(dp[i] != -1) return dp[i];
        int ans = 0;
        for(int j=0; j<w.size(); j++){
            int k = i+w[j].size(), ws = w[j].size();
            if(k<=s.size() && s.substr(i,ws) == w[j]){
                ans = ans || wordCheck(s, i+ws, w, dp);
            }
        }
        return dp[i] = ans;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        return wordCheck(s, 0, wordDict, dp);
    }
};