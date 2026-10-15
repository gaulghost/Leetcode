class Solution {
public:
    void addvec(vector<vector<int>>& ans, vector<int>& cand, int target, vector<int> temp, int i){
        if(target == 0){
            ans.push_back(temp);
            return;
        } else if (i >= cand.size() || target < 0) return;
        addvec(ans, cand, target, temp, i+1);
        if(cand[i] <= target){
            temp.push_back(cand[i]);
            addvec(ans, cand, target-cand[i], temp, i);
        }
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        addvec(ans, candidates, target, {}, 0);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna