class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> m;
        for(int i: nums) m[i]++;
        priority_queue<pair<int, int>> pq;
        for (auto& [i, j] : m) {
            pq.push({j, i});
        }
        while(!pq.empty() && k-- > 0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna