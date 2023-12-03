class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0, i = points[0][0], j = points[0][1];
        for(vector<int> point: points){
            int i_new = point[0], j_new = point[1];
            int diagonal = min(abs(i-i_new), abs(j-j_new));
            int ver_hoz = max(abs(i-i_new), abs(j-j_new)) - diagonal;
            ans += diagonal + ver_hoz;
            i = i_new;
            j = j_new;
        }
        return ans;
    }
};