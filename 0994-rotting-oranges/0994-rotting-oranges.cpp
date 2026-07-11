class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> rotten;
        int farthestOrangeDist = 0, cnt = 0;
        for(int i =0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 2){
                    rotten.push({i,j});
                }
                if(grid[i][j] == 1) cnt++;
            }
        }
        if(cnt == 0) return 0;
        while(!rotten.empty()){
            int sz = rotten.size();
            for(int k=0; k<sz; k++){
                int i = rotten.front().first;
                int j = rotten.front().second;
                rotten.pop();
                if(i+1<grid.size() && grid[i+1][j] == 1){
                    rotten.push({i+1, j});
                    grid[i+1][j] = 2;
                }
                if(i>0 && grid[i-1][j] == 1){
                    rotten.push({i-1, j});
                    grid[i-1][j] = 2;
                }
                if(j+1<grid[0].size() && grid[i][j+1] == 1){
                    rotten.push({i, j+1});
                    grid[i][j+1] = 2;
                }
                if(j>0 && grid[i][j-1] == 1){
                    rotten.push({i, j-1});
                    grid[i][j-1] = 2;
                }
            }
            farthestOrangeDist++;
        }
        for(int i =0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return farthestOrangeDist-1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna