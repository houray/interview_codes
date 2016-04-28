class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid[0].size();
        int n = grid.size();
        int *matrix = new int[m * n];
        matrix[0] = grid[0][0];
        for (int i = 1; i < m * n; ++i) {
            int p = i % m;
            int q = i / m;
            if (!p) {
                matrix[i] = matrix[i - m] + grid[q][p];
                continue;
            }
            if (!q) {
                matrix[i] = matrix[i - 1] + grid[q][p];
                continue;
            }
            if (p && q) {
                matrix[i] = matrix[i - 1] + grid[q][p] < matrix[i - m] + grid[q][p] ? matrix[i - 1] + grid[q][p] : matrix[i - m] + grid[q][p];
            }
        }
        return matrix[m * n - 1];
    }
};