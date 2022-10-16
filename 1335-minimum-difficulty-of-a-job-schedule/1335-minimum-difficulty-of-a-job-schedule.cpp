class Solution {
public:
    int dp[11][301];
    int recur(vector<int>& jd, int d, int cur, vector<vector<int>>& dp){
        if(d<0) return INT_MAX;
        if(cur >= jd.size()){
            if(d == 0) return 0;
            return INT_MAX;
        }
        if(dp[d][cur] != -1) return dp[d][cur];
        int val = INT_MAX, md = 0;
        int sz = (jd.size()-d+1 < jd.size())? jd.size()-d+1 : jd.size();
        for(int i=cur; i<sz ; i++){
            md = max(md, jd[i]);
            int temp = recur(jd, d-1, i+1, dp);
            if(temp == INT_MAX) continue;
            else val = min(val, md + temp);
        }
        return dp[d][cur] = val;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size() < d) return -1;
        vector<vector<int>> dp(d+1, vector<int>(jobDifficulty.size()+1, -1));
        int ans = recur(jobDifficulty, d, 0, dp);
        if(ans == INT_MAX) return -1;
        return ans;
    }
};