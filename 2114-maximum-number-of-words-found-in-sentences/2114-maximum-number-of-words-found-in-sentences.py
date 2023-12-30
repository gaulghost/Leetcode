class Solution:
    def countWords(str_sen : str) -> int:
        ans =0
        for i in range(0,len(str_sen)):
            if(str_sen[i] == ' '):
                ans += 1
        return ans+1
    
    def mostWordsFound(self, sentences: List[str]) -> int:
        ans=0
        for i in range(0, len(sentences)):
            count = Solution.countWords(sentences[i])
            ans = max(ans, count)
        return ans
            
            
        