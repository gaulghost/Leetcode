class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        stack<int> s;
        for(int i=0; i<nums.size(); i++){
            while(!s.empty() && nums[i] > nums[s.top()]){
                ans[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()){        
            int i=0;
            while(i < s.top()){
                if(nums[i] > nums[s.top()]){
                    ans[s.top()] = nums[i];
                    break;
                }
                i++;
            }
            s.pop();
        }
        return ans; 
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna