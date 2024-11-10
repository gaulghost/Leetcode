class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> v1 (s.size(), vector<int> (s.size(), 0));
        for(int i =0; i<s.size(); i++){
            v1[i][i] = 1;
            if(i<s.size()-1){
                if(s[i] == s[i+1]) v1[i][i+1] = 1;
            }
        }
        for(int i = 2; i<s.size(); i++){
            for(int j=0; j<s.size()-i; j++){
                if(s[j+i] == s[j] && v1[j+1][j+i-1] == 1) v1[j][j+i] = 1;
            }
        }
        int maxans = 0, start = 0, end = 0;
        for(int i =0; i<s.size(); i++){
            for(int j=i; j<s.size(); j++){
                if(v1[i][j] == 1 && abs(i-j) > maxans){
                    maxans = abs(i-j);
                    start = i;
                    end = j;
                }
            }
        }
        return s.substr(start, maxans+1);        
    }
};