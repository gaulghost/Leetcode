class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> sc;
        for(char c : s){
            if(sc.empty()) sc.push(c);
            else if (sc.top() == c) sc.pop();
            else sc.push(c);
        }
        string ans = "";
        while(!sc.empty()){
            ans += sc.top();
            sc.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};