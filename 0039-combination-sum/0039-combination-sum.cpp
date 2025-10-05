#include <vector>
#include <algorithm>

class Solution {
public:
    void backtrack(vector<vector<int>>& result, vector<int>& current_combination, 
                   vector<int>& candidates, int remaining_target, int start_index) {
        
        // Base Case 1: A valid combination is found.
        if (remaining_target == 0) {
            result.push_back(current_combination);
            return;
        }

        // Base Case 2: The path is invalid (sum exceeds target). Prune this branch.
        if (remaining_target < 0) {
            return;
        }

        // Explore possibilities.
        for (int i = start_index; i < candidates.size(); ++i) {
            // 1. Choose: Add the candidate to the 
            // current combination.
            current_combination.push_back(candidates[i]);
            
            // 2. Explore: Recurse with the updated target.
            // We pass 'i' as the new start_index, not 'i + 1', 
            // because we can reuse the same number.
            backtrack(result, current_combination, candidates, remaining_target - candidates[i], i);

            // 3. Un-choose (Backtrack): 
            // Remove the candidate to explore other paths.
            // This is the crucial step that allows 
            // us to backtrack to the previous state.
            current_combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current_combination;
        // Sorting is an optimization to potentially prune 
        // the search earlier, but not required for correctness.
        // std::sort(candidates.begin(), candidates.end()); 
        backtrack(result, current_combination, candidates, target, 0);
        return result;
    }
};