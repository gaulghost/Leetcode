class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int qf = q.front();
            for(int i=0; i<adj[qf].size(); i++){
                indegree[adj[qf][i]]--;
                if(indegree[adj[qf][i]] == 0) q.push(adj[qf][i]);
            }
            q.pop();
        }
        for(int i:indegree){
            if(i!=0) return false;
        }
        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna