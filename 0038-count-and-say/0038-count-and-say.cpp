class Solution {
public:
    string compute(string& str){
        string ans = "";
        char prev = str[0];
        int count = 0;
        for(int i=0; i<str.size(); i++){
            if(prev == str[i]) count++;
            else{
                ans += to_string(count) + prev;
                prev = str[i];
                count = 1;
            }
        }
        ans += to_string(count) + prev;
        return ans;
    }
    
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 2; i<= n; i++){
            ans = compute(ans);
        }
        return ans;
    }
};