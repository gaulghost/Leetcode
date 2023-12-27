class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        // ans = [0, 2, 2, 2, 2, 5, ]
        // words = ["abc","bcd","aaaa","cbc", "fcadeah"], x = 'a'
        for(int i=0; i<words.size(); i++){
            // i=3, word[i] = "cbc"
            for(int j=0; j<words[i].size(); j++){
                // word[i].size() -> 3
                // j=2
                // word[i][j] -> 'c'
                // x = 'a'
                if(words[i][j] == x){
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};

