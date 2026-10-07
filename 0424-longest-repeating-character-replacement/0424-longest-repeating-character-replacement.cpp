class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> arr(26,0);
        int i=0, j=0, ans = 0;
        while(j<s.size()){
            if(i==j){
                arr[s[j++] - 'A']++;
                continue;
            }
            int tot = 0, ma = 0;
            for(int k=0; k<26; k++){
                tot += arr[k];
                ma = max(ma, arr[k]);
            }
            if(tot > ma + k){
                arr[s[i++]-'A']--;
            } else {
                ans = max(ans, tot);
                arr[s[j++]-'A']++;
            }
        }
        int tot = 0, ma = 0;
        for(int k=0; k<26; k++){
            tot += arr[k];
            ma = max(ma, arr[k]);
        }
        if(tot <= ma + k) ans = max(ans, tot);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna