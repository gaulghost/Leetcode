#include <iostream>

class Solution {
  public:
    void printTillN(int n) {
        // Recursively prints numbers from 1 to n without using loops.
        // Approach: call printTillN(n-1) first, then print n.
        // Time Complexity: O(n) – one call per number.
        // Space Complexity: O(n) – recursion depth = n (stack frames).
        // Note: For very large n, recursion may cause stack overflow.
        // An iterative solution would use O(1) space but loops are not allowed here.
        if (n <= 0) return;
        printTillN(n - 1);
        std::cout << n << " ";
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna