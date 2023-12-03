class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0, i = points[0][0], j = points[0][1];
        for(vector<int> point: points){
            ans += max(abs(i-point[0]), abs(j-point[1]));
            i = point[0];
            j = point[1];
        }
        return ans;
    }
};