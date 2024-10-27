//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int n = arr.size();
        int current_sum = arr[0], start = 0;

        // Traverse the array
        for (int i = 1; i <= n; i++) {
            // If current_sum exceeds the target, remove elements from the start
            while (current_sum > target && start < i - 1) { // Corrected "stqfqfqart" to "start"
                current_sum -= arr[start];
                start++;
            }

            // If current_sum becomes equal to the target, return the start and end indices
            if (current_sum == target) {
                return {start + 1, i}; // 1-based index
            }

            // Add the current element to current_sum if there are elements left
            if (i < n) {
                current_sum += arr[i];
            }
        }

        // If no subarray is found, return -1
        return {-1};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore(); // Ignore the newline character after d

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends