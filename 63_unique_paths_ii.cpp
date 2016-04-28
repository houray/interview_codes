class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid[0].size();
        int n = obstacleGrid.size();
        int i = 1;
        int *matrix = new int[m * n];
        matrix[0] = 1 - obstacleGrid[0][0];
        while (i < m * n) {
            int q = i % m;
            int p = i / m;
            if (obstacleGrid[p][q]) {
                matrix[i] = 0;
            } else {
                if (!p) {
                    matrix[i] = matrix[i - 1];
                }
                if (!q) {
                    matrix[i] = matrix[i - m];
                }
                if (p && q) {
                    matrix[i] = matrix[i - m] + matrix[i - 1];
                }
            }
            ++i;
        }
        return matrix[m * n - 1];
    }
};