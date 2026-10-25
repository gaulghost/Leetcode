class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // testing force push
        // This comment appears to be a placeholder. The implementation below correctly solves the Two Sum problem using a hash map.
        // Time Complexity: O(n) – each element is processed once.
        // Space Complexity: O(n) – extra space for the unordered_map storing at most n entries.
        unordered_map<int, int> idx;
        for (int i = 0; i < (int)nums.size(); ++i) {
            int complement = target - nums[i];
            auto it = idx.find(complement);
            if (it != idx.end()) {
                return {it->second, i};
            }
            idx[nums[i]] = i;
        }
        // If no solution is found (problem guarantees one), return empty vector.
        return {};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna