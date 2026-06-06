class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numToIndex;
        for(int i=0; i<nums.size(); i++) numToIndex[nums[i]] = i;
        for(int i=0; i<nums.size(); i++){
            if(numToIndex.find(target-nums[i]) != numToIndex.end() && i != numToIndex[target-nums[i]]){
                return {i, numToIndex[target-nums[i]]};
            }
        }
        return {};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna