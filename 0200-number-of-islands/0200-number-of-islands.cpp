class Solution {
public:
    void markVis(vector<vector<char>>& grid, int i, int j){
        if(i<0 || i>=grid.size() || j<0 || j>= grid[i].size()) return;
        if(grid[i][j] == '0') return;
        grid[i][j] = '0';
        markVis(grid, i+1, j);
        markVis(grid, i-1, j);
        markVis(grid, i, j+1);
        markVis(grid, i, j-1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] == '1') markVis(grid, i, j), ans++;
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna