class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int left = 0, maxFreq = 0, ans = 0;
        for (int right = 0; right < s.size(); right++) {
            maxFreq = max(maxFreq, ++count[s[right] - 'A']);
            while ((right - left + 1) - maxFreq > k) {
                count[s[left++] - 'A']--;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna