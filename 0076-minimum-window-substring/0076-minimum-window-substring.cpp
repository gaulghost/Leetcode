class Solution {
public:
    void reduceWindow(int& start, int& end, string& s, unordered_map<char, int>& m, int& ans, int& bstart){
        while(start < s.size() && (m.find(s[start]) == m.end() || m[s[start]]>0)){
            if(m.find(s[start]) != m.end()) m[s[start]]--;
            start++;
            if(end-start < ans){
                ans = end-start;
                bstart = start;
            }
        }
    }
    
    string minWindow(string s, string t) {
        int i=0;
        unordered_map<char, int> m, mn;
        for(auto c : t) mn[c]++;
        for(auto c : t) m[c] = 0;
        while(!mn.empty()){
            if(i == s.size()) return "";
            if(mn.find(s[i]) == mn.end() && m.find(s[i]) != m.end()) m[s[i]]++;
            if(mn.find(s[i]) != mn.end()){
                if(mn[s[i]] == 1) mn.erase(s[i]);
                else mn[s[i]]--;
            }
            i++;
        }
        int ans = i, start = 0, end = i, bstart = 0;
        while(end < s.size()){
            reduceWindow(start, end, s, m, ans, bstart);
            start++;
            while(end<s.size() && s[end]!= s[start-1]){
                if(m.find(s[end]) != m.end()) m[s[end]]++;
                end++;
            }
            end++;
            if(end < s.size() && end-start < ans){
                ans = end-start;
                bstart = start;
            }
        }
        if(end <= s.size()) reduceWindow(start, end, s, m, ans, bstart);
        return s.substr(bstart, ans);
    }
};