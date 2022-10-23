class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long n = nums.size(), sum = (n*(n+1))/2, sqsum = (n*(n+1)*(2*n+1))/6;
        long arr_sum = 0, arr_sqsum =0;
        for(int i : nums){
            arr_sum += i;
            arr_sqsum += i*i;
        }
        int s = sum - arr_sum, p = sqsum - arr_sqsum, m = (s+p/s)/2, r = m - s;
        return {r, m};
    }
};