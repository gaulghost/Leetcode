class Solution {
public:
    int findParent(int i, vector<int>& parent){
        return parent[i] == i ? i : parent[i] = findParent(parent[i], parent);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(edges.size()+1, 0);
        for(int i=0; i<parent.size(); i++) parent[i] = i;
        for(int i=0; i<edges.size(); i++){
            int a = findParent(edges[i][0], parent), b = findParent(edges[i][1], parent);
            cout<<edges[i][0]<<" "<<edges[i][1]<<" "<<a<<" "<<b<<endl;
            if(a==b) return edges[i];
            parent[a] = parent[b];
        }
        return {0,0};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna