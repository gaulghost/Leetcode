class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> lft(heights.size(), 0);
        vector<int> rgt(heights.size(), heights.size()-1);
        stack<int> s;
        for(int i=0; i<heights.size(); i++){
            while(!s.empty() && heights[s.top()]>=heights[i]) s.pop();
            if(!s.empty()) lft[i] = s.top()+1;
            s.push(i);
        }
        s={};
        for(int i=heights.size()-1; i<heights.size(); i--){
            while(!s.empty() && heights[s.top()]>=heights[i]) s.pop();
            if(!s.empty()) rgt[i] = s.top()-1;
            s.push(i);
        }
        int ans = 0;
        for(int i=0; i<heights.size(); i++)
            ans = max(ans, heights[i]*(rgt[i]-lft[i]+1));
        return ans;
    }
};

// left
// 0,0,2,3,2,5
// right
// 0,5,3,3,5,5





// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna