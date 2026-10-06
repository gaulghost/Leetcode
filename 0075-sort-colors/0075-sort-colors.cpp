class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0, j=0, k=nums.size()-1;
        while(j<=k && j<nums.size()){
            if(i>j){
                j=i;
                continue;
            }
            if(nums[j] == 0){
                swap(nums[i], nums[j]);
                i++;
            } else if(nums[j] == 1){
                j++;
            } else {
                swap(nums[k], nums[j]);
                k--;
            }
        }
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna