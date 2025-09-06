class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        int v1=1, v2=2;
        for(int i=3; i<n+1; i++){
            int v3 = v2;
            v2 = v1+v2;
            v1 = v3;
        }
        return v2;
    }
};