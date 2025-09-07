class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                if (nums[i] > nums[j]) {
                    ans[i] = max(ans[i], 1+ans[j]);
                }
            }
        }
        int as = 1;
        for (int i: ans) as = max(as, i);
        return as;
    }
};