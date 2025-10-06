class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0], nums[1]);
        vector<int> cpy = nums;
        for(int i=2; i<cpy.size(); i++){
            int m = 0;
            for(int j=0; j<i-1; j++){
                m = max(cpy[j], m);
            }
            cpy[i]=m+nums[i];
        }
        return max(cpy[nums.size()-1], cpy[nums.size()-2]);
    }
};
