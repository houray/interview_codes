class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> r(9, 0);
        vector<int> c(9, 0);
        vector<int> b(9, 0);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                int value = 1 << (board[i][j] - '0');
                if ((r[i] & value) > 0 || (c[j] & value) > 0 || (b[i/3 + j/3 * 3] & value) > 0) {
                    return false;
                }
                r[i] |= value;
                c[j] |= value;
                b[i/3 + j/3 * 3] |= value;
            }
        }
        return true;
    }
};
