class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, i = 0, j=height.size()-1, n = height.size(), maxl = 0, maxr = 0;
        while(j>=i){
            maxl = max(maxl, height[i]);
            maxr = max(maxr, height[j]);
            if(height[i] > height[j]){
                ans += min(maxl, maxr) - height[j];
                j--;
            } else {
                ans += min(maxl, maxr) - height[i];
                i++;
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna