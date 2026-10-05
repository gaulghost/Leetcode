class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> num = nums;
        unordered_set<string> us;
        sort(num.begin(), num.end());
        for(int i=0; i<num.size()-2; i++){
            int j = i+1, k = num.size()-1;
            while(k>j){
                if(num[i] + num[j] + num[k] == 0){
                    string s = to_string(num[i]) + "_"  + to_string(num[j]) + "_" + to_string(num[k]);
                    if(us.find(s) == us.end()){
                        us.insert(s);
                        ans.push_back({num[i], num[j], num[k]});
                    }
                    j++, k--;
                } else if (num[i] + num[j] + num[k] > 0) k--;
                else j++;
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna