#include <iostream>

class Solution {
  public:
    void printTillN(int n) {
        // This function correctly prints numbers from 1 to n using recursion.
        // Time Complexity: O(n) because it makes a single recursive call for each integer from n down to 1.
        // Space Complexity: O(n) due to the recursion stack depth (n calls). An iterative version could achieve O(1) extra space.
        if (n <= 0) return;
        printTillN(n - 1);
        std::cout << n << " ";
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna