class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        int si = grid[0].size(), sj = grid.size();
        for(int m=0; m<si; m++){
            int ball = 1, i = m, j = 0;
            while(j < sj){
                if(grid[j][i] == 1 && (i+1 >= si || grid[j][i+1] == -1)){
                    ans.push_back(-1);
                    break;
                }
                if(grid[j][i] == -1 && (i-1 < 0 || grid[j][i-1] == 1)){
                    ans.push_back(-1);
                    break;
                }
                if(grid[j][i] == 1) i++;
                else i--;
                j++;
            }
            if(j >= sj) ans.push_back(i);
        }
        return ans;
    }
};