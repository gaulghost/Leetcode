class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        int f = min((int)matrix.size(), k+1);
        for (int i=0; i<f; i++){
            int v = min((int)matrix[i].size(), k+1);
            for(int j=0; j<v; j++){
                pq.push(matrix[i][j]);
                if(pq.size() == k+1) pq.pop();
            }
        }
        return pq.top();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna