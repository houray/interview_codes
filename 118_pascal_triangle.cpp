class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> generate(int numRows) {
        if (numRows < 1) { return result; }
        for (int i = 0; i < numRows; ++i) {
            vector<int> curr(1, 1);
            if (i > 0) {
                for (int j = 0; j < result[i - 1].size() - 1; ++j) {
                    curr.push_back(result[i - 1][j] + result[i - 1][j + 1]);
                }
                curr.push_back(1);
            }
            result.push_back(curr);
        }
        return result;
    }
};