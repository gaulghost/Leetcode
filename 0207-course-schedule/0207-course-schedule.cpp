class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indeg(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(int i=0; i<prerequisites.size(); i++){
            indeg[prerequisites[i][0]]++;
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> q;
        for(int i=0; i<indeg.size(); i++) if(indeg[i] == 0) q.push(i);
        while(!q.empty()){
            int i = q.front(); q.pop();
            for(int k=0; k<adj[i].size(); k++){
                if(--indeg[adj[i][k]] == 0) q.push(adj[i][k]);
            }
        }
        for(int i:indeg) if(i>0) return false;
        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna