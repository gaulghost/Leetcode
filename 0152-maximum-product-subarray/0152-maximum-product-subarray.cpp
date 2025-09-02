class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), k=1, f=1, ans=INT_MIN;
        int start = 1, end = 1;
        for(int i=0; i<n; i++){
            start = start*nums[i];
            end = end*nums[n-i-1];
            ans = max(ans, max(start,end));
            if(nums[i] == 0) start = 1;
            else if (nums[n-i-1] == 0) end = 1;
        }
        return ans;
    }
};