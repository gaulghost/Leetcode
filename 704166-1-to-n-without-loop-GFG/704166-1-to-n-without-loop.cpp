#include <iostream>

class Solution {
  public:
    void printTillN(int n) {
        // submit test
        if (n <= 0) return;
        printTillN(n - 1);
        std::cout << n << " ";
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna