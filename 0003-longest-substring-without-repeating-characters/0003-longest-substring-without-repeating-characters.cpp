class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        if(s.size() == 1) return 1;
        set<char> arr;
        int i=0, j=0, ans=0;
        while(j<s.size()){
            ans = max(ans, j-i);
            if(!arr.contains(s[j])){
                arr.insert(s[j]);
                j++;
            } else {
                arr.erase(s[i]);
                i++;
            }
        }
        ans = max(ans, j-i);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna