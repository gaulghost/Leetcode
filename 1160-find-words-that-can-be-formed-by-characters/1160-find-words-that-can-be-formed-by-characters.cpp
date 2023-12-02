class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> m;
        for(char ch: chars){
            if(m.find(ch) == m.end()) m[ch] = 1;
            else m[ch]++;
        }
        int ans = 0;
        for(string word: words){
            unordered_map<char, int> m_cpy = m;
            int unsuccess = 0;
            for(char cha : word){
                if(m_cpy.find(cha) != m_cpy.end()){
                    m_cpy[cha]--;
                    if(m_cpy[cha]<0){
                        unsuccess = 1;
                        break;
                    }
                }
                else {
                    unsuccess = 1;
                    break;
                }
            }
            if(!unsuccess) ans+= word.size();
        }
        return ans;
    }
};