/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int call(long long start, long long end){
        long long mid = (start+end)/2, val = guess(mid);
        if(val == 0) return mid;
        else if(val == 1) return call(mid+1, end);
        return call(start, mid-1);
    }
    
    int guessNumber(int n) {
        int ans = call(0, n);
        return ans;
    }
};