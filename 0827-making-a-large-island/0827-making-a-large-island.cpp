class Solution {
public:
    void markIsland(int i, int j, vector<vector<int>>& vis,vector<vector<int>>& grid, int islandNo){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || vis[i][j] != 0 || grid[i][j] == 0)
            return;
        vis[i][j] = islandNo;
        markIsland(i+1,j,vis,grid,islandNo);
        markIsland(i-1,j,vis,grid,islandNo);
        markIsland(i,j+1,vis,grid,islandNo);
        markIsland(i,j-1,vis,grid,islandNo);
    }

    int largestIsland(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int> (grid[0].size(), 0));
        int islandNo = 1;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    markIsland(i,j,vis,grid,islandNo);
                    islandNo++;
                } 
            }
        }
        // islandNo,  size
        unordered_map<int, int> um;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(vis[i][j] != 0)
                    um[vis[i][j]]++;
            }
        }
        int largestIslandSz = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(vis[i][j] == 0){
                    unordered_set<int> us;
                    if(i+1 < grid.size()) us.insert(vis[i+1][j]);
                    if(i-1 >= 0) us.insert(vis[i-1][j]);
                    if(j+1 < grid[0].size()) us.insert(vis[i][j+1]);
                    if(j-1 >= 0) us.insert(vis[i][j-1]);
                    int totalsz = 0;
                    for(int i: us) totalsz += um[i];
                    largestIslandSz = max(largestIslandSz, totalsz+1);
                } else {
                    largestIslandSz = max(largestIslandSz, um[vis[i][j]]);
                }
            }
        }
        return largestIslandSz;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna