class Solution {
public:
    string minWindow(string s, string t) {
        // My soln re-written by AI
        if (s.size() < t.size()) return "";
        unordered_map<char, int> ums, um2;
        for (char c : t) {
            ums[c]++;
            um2[c]--;
        }
        int i = 0, j = 0;
        // Phase 1: Expand j until we find the first valid window
        while (!ums.empty() && j < s.size()) {
            um2[s[j]]++;
            if (ums.contains(s[j])) {
                ums[s[j]]--;
                if (ums[s[j]] == 0) ums.erase(s[j]);
            }
            j++;
        }
        if (!ums.empty()) return ""; // Could not even satisfy t
        // Initial shrink: Remove any surplus characters from the beginning
        while (i < j && um2[s[i]] > 0) {
            um2[s[i++]]--;
        }
        string ans = s.substr(i, j - i);
        // Phase 2: Slide and continuously shrink surplus
        while (j < s.size()) {
            // Expand j
            um2[s[j++]]++;
            // Shrink any surplus from the left
            while (i < j && um2[s[i]] > 0) {
                um2[s[i++]]--;
            }
            // If this window is smaller, update ans
            if (j - i < ans.size()) {
                ans = s.substr(i, j - i);
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna