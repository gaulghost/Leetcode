class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> rot;
        int tot = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 2) rot.push({i,j});
                if(grid[i][j] == 1) tot++;
            }
        }
        if(tot == 0) return 0;
        int time = 0;
        while(!rot.empty()){
            int sz = rot.size();
            for(int k=0; k<sz; k++){
                auto [i, j] = rot.front(); rot.pop();
                if(i>0 && grid[i-1][j]==1){
                    grid[i-1][j] = 2;
                    rot.push({i-1, j});
                    tot--;
                }
                if(i+1<grid.size() && grid[i+1][j]==1){
                    grid[i+1][j] = 2;
                    rot.push({i+1, j});
                    tot--;
                }
                if(j>0 && grid[i][j-1]==1){
                    grid[i][j-1] = 2;
                    rot.push({i, j-1});
                    tot--;
                }
                if(j+1<grid[0].size() && grid[i][j+1]==1){
                    grid[i][j+1] = 2;
                    rot.push({i, j+1});
                    tot--;
                }
            }
            time++;
        }
        return tot == 0 ? time-1 : -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna