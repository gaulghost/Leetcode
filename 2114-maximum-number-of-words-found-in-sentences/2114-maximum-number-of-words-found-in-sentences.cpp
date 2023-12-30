class Solution {
public:
    int countWords(string sentence){
        int no_of_spaces = 0;
        for(char c: sentence){
            if(c==' '){
                no_of_spaces++;
            }
        }
        return no_of_spaces+1;
    }   
    
    int mostWordsFound(vector<string>& sentences) {
        int ans =0;
        for (string s: sentences){
            int no_of_words = countWords(s);
            ans = max(ans, no_of_words);
        }
        return ans;
    }
};