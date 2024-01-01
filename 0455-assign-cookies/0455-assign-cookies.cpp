class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        vector<int> g_cpy = g, s_cpy = s;
        int ans =0;
        sort(g_cpy.begin(), g_cpy.end());
        sort(s_cpy.begin(), s_cpy.end());
        int j =0;
        for(int i=0; i<s_cpy.size(); i++){
            if(j == g_cpy.size()) break;
            if(g_cpy[j] <= s_cpy[i]){
                ans++;
                j++;
            }
            else continue;
        }
        return ans;
    }
};