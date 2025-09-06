class Solution {
public:
    int climbStairs(int n) {
        int v1=1, v2=2;
        if(n==1) return v1;
        if(n==2) return v2;
        for(int i=3; i<n+1; i++){
            int v3 = v2;
            v2 = v1+v2;
            v1 = v3;
        }
        return v2;
    }
};