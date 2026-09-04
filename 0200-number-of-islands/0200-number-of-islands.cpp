class Solution {
public:
    void markIslandVisited(int i, int j, vector<vector<char>>& grid){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        markIslandVisited(i+1,j,grid);
        markIslandVisited(i-1,j,grid);
        markIslandVisited(i,j+1,grid);
        markIslandVisited(i,j-1,grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    markIslandVisited(i, j, grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna