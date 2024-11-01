class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // This code is about finding the largest substring possible in the provided string.
        unordered_map<char, int> m;
        int behind = 0, ans = 0;
        for(int i =0; i<s.size(); i++){
            if(m.find(s[i]) == m.end() || (m.find(s[i]) != m.end() && m[s[i]] < behind)){
                m[s[i]] = i;
                ans = max(ans, i-behind+1);
            }
            else{
                behind = m[s[i]]+1;
                m[s[i]] = i;
            }
        }
        return ans;
    }
};