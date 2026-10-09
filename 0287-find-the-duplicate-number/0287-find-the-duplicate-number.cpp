class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = nums[nums[0]], slow = nums[0];
        while(fast != slow){
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        fast = 0;
        while(fast != slow){
            fast = nums[fast];
            slow = nums[slow];
        }
        return fast;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna