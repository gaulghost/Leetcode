class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<1) return 0;
        unordered_set<char> dp;
        dp.insert(s[0]);
        int ans = 1, st = 0, end=1;
        while(end<s.size()){
            if(dp.find(s[end]) == dp.end()){
                dp.insert(s[end]);
            } else {
                while(s[st] != s[end]){
                    dp.erase(s[st]);
                    st++;
                }
                st++;
            }
            end++;
            ans = max(ans, (int)dp.size());
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna