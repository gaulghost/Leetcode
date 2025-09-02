class Solution {
public:
    int findMin(vector<int>& nums) {
        int start=0, end=nums.size()-1, ans=INT_MAX;
        while(start<=end){
            int mid = (start+end)/2;
            ans = min(ans, nums[mid]);
            if(nums[mid] > nums[end]){
                start = mid+1;
            } else {
                end = mid-1;
            }
        }
        return ans;
    }
};