class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // what is question about? tell me the best solution and its time and
        // space complexity The problem asks for indices of two numbers that add
        // up to the target. Use a hash map for O(N) time and O(N) extra space.
        unordered_map<int, int> idx; // maps number value to its index
        for (int i = 0; i < (int)nums.size(); ++i) {
            int complement = target - nums[i];
            auto it = idx.find(complement);
            if (it != idx.end()) {
                return {it->second, i};
            }
            idx[nums[i]] = i;
        }
        return {}; // guaranteed to have a solution, this line is just for
                   // completeness

        // is this the best solution?
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna