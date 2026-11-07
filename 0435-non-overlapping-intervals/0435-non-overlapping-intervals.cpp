class Solution {
public:
    static bool myComp(vector<int>& v1, vector<int>& v2){
        return v1[1] < v2[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), myComp);
        int ans = 0, nonSkipped = 0;
        for(int i=1; i<intervals.size(); i++){
            if (intervals[i-1][0] != INT_MIN) nonSkipped = i-1;
            if (intervals[i][0] < intervals[nonSkipped][1]){
                ans++;
                intervals[i] = {INT_MIN,INT_MIN};
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna