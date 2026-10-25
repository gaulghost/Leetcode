class Solution {
public:
    // Two Sum solution using a hash map for O(n) time.
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> idx; // map from number to its index
        for (int i = 0; i < (int)nums.size(); ++i) {
            int complement = target - nums[i]; // value needed to reach target
            auto it = idx.find(complement);
            if (it != idx.end()) {
                // Found the pair: return indices of complement and current element
                return {it->second, i};
            }
            // Store the current number and its index for future complement checks
            idx[nums[i]] = i;
        }
        // No pair found (the problem guarantees a solution, so this is just a fallback)
        return {};
    }
    // Time Complexity: O(n) where n = nums.size().
    // Space Complexity: O(n) due to the hash map storing up to n entries.
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna