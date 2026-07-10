class Solution {
public:
    void markIslandVisited(int i, int j, vector<vector<int>>& map, vector<vector<char>>& grid){
        if(grid[i][j] == '0') return;
        if(map[i][j] == 1) return;
        map[i][j] = 1;
        int g_sz = grid.size(), gl_sz = grid[0].size();
        if(i+1 < g_sz && grid[i+1][j] == '1') markIslandVisited(i+1,j,map,grid);
        if(i-1 >= 0 && grid[i-1][j] == '1') markIslandVisited(i-1,j,map,grid);
        if(j+1 < gl_sz && grid[i][j+1] == '1') markIslandVisited(i,j+1,map,grid);
        if(j-1 >= 0 && grid[i][j-1] == '1') markIslandVisited(i,j-1,map,grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int totalIslands = 0;
        vector<vector<int>>map(grid.size(), vector<int>(grid[0].size(),0));
        for(int i=0; i<grid.size(); i++){
            for (int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == '1' and map[i][j] == 0){
                    markIslandVisited(i, j, map, grid);
                    totalIslands++;
                }
            }
        }
        return totalIslands;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna