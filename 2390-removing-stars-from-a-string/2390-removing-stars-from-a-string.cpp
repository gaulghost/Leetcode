class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for (char c: s){
            if(c == '*' && !st.empty()) st.pop();
            else if (c != '*') st.push(c);
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};