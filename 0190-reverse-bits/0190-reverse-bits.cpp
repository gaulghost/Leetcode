class Solution {
public:
    int reverseBits(int n) {
        int i=0, ans=0;
        while(n!=0){
            int carry = n&1;
            ans = ans | (carry<<(31-i++));
            n=n>>1;
        }
        return ans;
    }
};