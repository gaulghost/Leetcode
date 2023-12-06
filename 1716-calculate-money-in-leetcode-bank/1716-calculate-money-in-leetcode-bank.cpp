class Solution {
public:
    int totalMoney(int n) {
        int div = n/7, rem = n%7;
        int fixed = 28*div + ((div-1)*div/2)*7;
        int varia = rem*(2*div+1+rem)/2;
        return fixed + varia;
    }
};