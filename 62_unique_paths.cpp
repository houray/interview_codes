class Solution {
public:
    int uniquePaths(int m, int n) {
        int *matrix = new int[m * n];
        for (int i = 0; i < m * n; ++i) {
            int p = i % m;
            int q = i / m;
            if (!p || !q) {
                matrix[i] = 1;
            } else {
                matrix[i] = matrix[i - 1] + matrix [i - m];
            }
        }
        return matrix[m * n - 1];
    }
};