class Solution {
public:
    int findMin(vector<int>& nums) {
        int i=0, j=nums.size()-1, smal = nums[0];
        while(i<=j){
            int mid = (i+j)/2;
            smal = min(smal, nums[mid]);
            if(nums[mid] < nums[i]){
                if(nums[j] > nums[mid]) j = mid-1;
                else i = mid+1;
            } else {
                if(nums[mid] >= nums[j]) i = mid+1;
                else j = mid-1;
            }
        }
        return smal;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna