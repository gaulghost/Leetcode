class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1;
        unordered_map<char, pair<int, int>> m;
        for(int i=0; i<s.size(); i++){
            if(m.find(s[i]) == m.end()) m[s[i]] = {i,i};
            else{
                m[s[i]].second = i; 
            }
        }
        for(auto i : m){
            if(i.second.second-i.second.first > 0) {
                ans = max(ans, i.second.second-i.second.first-1);
            }
        }
        return ans;
    }
};