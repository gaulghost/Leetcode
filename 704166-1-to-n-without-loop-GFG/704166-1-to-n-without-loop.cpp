#include <iostream>

class Solution {
  public:
    void printTillN(int n) {
        // Recursively prints numbers from 1 to n without using loops.
        // Base case: when n <= 0, stop recursion.
        // Recursive case: first print numbers up to n-1, then print n.
        // Time Complexity: O(n) – each integer is printed exactly once.
        // Space Complexity: O(n) – recursion depth equals n (call stack).
        if (n <= 0) return;
        printTillN(n - 1);
        std::cout << n << " ";
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna