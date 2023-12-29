class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int result = 0;
        for (string x : operations){
            if (x == "--X") {
                result -= 1;
            } else if (x == "X--") {
                result -= 1;
            } else if (x == "++X") {
                result += 1;
            } else {
                result += 1;
            }
        }
        return result;
    }
};