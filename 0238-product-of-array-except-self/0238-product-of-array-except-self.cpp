class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans = nums;
        int val = 1, prefix = 1;
        for(int i=0; i<nums.size()-1; i++){
            val = val*nums[i];
            ans[i] = val;
        }
        for(int i=nums.size()-1; i>0; i--){
            ans[i] = ans[i-1]*prefix;
            prefix = prefix * nums[i];
        }
        ans[0] = prefix;
        return ans;
    }
};