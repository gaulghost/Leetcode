class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), 0));
        for(int i=0; i<text1.size(); i++){
            for(int j=0; j<text2.size(); j++){
                int k = 0, l = 0, m=0;
                if(i-1>=0) k=dp[i-1][j];
                if(j-1>=0) l=dp[i][j-1];
                if(i-1>=0 && j-1>=0) m=dp[i-1][j-1];
                if(text1[i] == text2[j]){
                    dp[i][j] = 1 + m;
                } else dp[i][j] = max(k,l);
                cout<<dp[i][j]<<" "<<i<<" "<<j<<endl;
            }
        }
        return dp[text1.size()-1][text2.size()-1];
    }
};