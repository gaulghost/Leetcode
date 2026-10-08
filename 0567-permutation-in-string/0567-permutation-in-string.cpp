class Solution {
public:
    bool isEqual(vector<int> &a1, vector<int> &a2){
        for(int i=0; i<26; i++){
            if(a1[i] != a2[i]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false;
        vector<int> a1(26,0);
        vector<int> a2(26,0);
        for(int i=0; i<s1.size(); i++){
            a1[s1[i]-'a']++;
            a2[s2[i]-'a']++;
        }
        for(int i=s1.size(); i<s2.size(); i++){
            if(isEqual(a1, a2)) return true;
            a2[s2[i]-'a']++;
            a2[s2[i-s1.size()]-'a']--;
        }
        if(isEqual(a1, a2)) return true;
        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna