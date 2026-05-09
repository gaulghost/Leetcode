class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 2) return num == 1;
        int sqrt_num = sqrt(num);
        return sqrt_num * sqrt_num == num;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna