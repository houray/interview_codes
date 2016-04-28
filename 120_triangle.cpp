class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0) { return 0; }
        for (int i = 1; i < triangle.size(); ++i) {
            triangle[i][0] += triangle[i - 1][0];
            for(int j = 1; j < triangle[i].size() - 1; ++j) {
                triangle[i][j] += (triangle[i - 1][j - 1] < triangle[i - 1][j] ? triangle[i - 1][j - 1] : triangle[i - 1][j]);
            }
            triangle[i][triangle[i].size() - 1] += triangle[i - 1][triangle[i - 1].size() - 1];
        }
        int n = triangle.size() - 1;
        int min = triangle[n][0];
        for (int i = 1; i < triangle[n].size(); ++i) {
            min = min < triangle[n][i] ? min : triangle[n][i];
        }
        return min;
    }
};