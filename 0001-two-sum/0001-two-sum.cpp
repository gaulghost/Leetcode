class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> idx; // maps number -> its index
        for (int i = 0; i < (int)nums.size(); ++i) {
            int complement = target - nums[i];
            auto it = idx.find(complement);
            if (it != idx.end()) {
                // Complement found: return the stored index and current index.
                return {it->second, i};
            }
            // Store the current number and its index for future complement checks.
            idx[nums[i]] = i;
        }
        // If no solution is found (the problem guarantees a solution), return an empty vector.
        return {};
        // Time Complexity: O(n) where n = nums.size()
        // Space Complexity: O(n) for the hash map.
        // This is optimal for the Two Sum problem; no better asymptotic solution exists.
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna