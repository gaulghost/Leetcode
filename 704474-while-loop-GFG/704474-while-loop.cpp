class Solution {
  public:
    void utility(int x) {
        // Use a while loop to process 'x' until condition is met
        // Example approach: Initialize a counter, loop while counter > 0, decrement inside loop
        int count = x;
        while (count >= 0) {
            // Process here
            cout<<count;
            if(count != 0) cout<<" ";
            count--;
        }
        // what is time complexity of this
        // Time Complexity: O(n) where n = x (loop runs x+1 times)
        // Space Complexity: O(1) (constant space for variables)
        // This is optimal for this straightforward iterative approach
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna