class Solution {
public:
    bool detectCapitalUse(string word) {
        int isSmall = 0, isBig = 0;
        for(int i=1; i<word.size(); i++){
            if(word[i]-'a' >= 0 && word[i]-'a' < 27 && isBig != 1)
                isSmall = 1;
            else if(word[i]-'A' >= 0 && word[i]-'A' < 27 && isSmall != 1)
                isBig = 1;
            else return false;
        }
        if(isBig == 1 && !(word[0]-'A' >= 0 && word[0]-'A' < 27))
            return false;
        return true;
    }
};