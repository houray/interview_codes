class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> curr;
        vector<int> prev;
        if (rowIndex < 0) { return curr; }
        for (int i = 0; i <= rowIndex; ++i) {
            prev = curr;
            curr.clear();
            curr.push_back(1);
            if (i > 0) {
                for(int j = 0; j < prev.size() - 1; ++j) {
                    curr.push_back(prev[j] + prev[j + 1]);
                }
                curr.push_back(1);
            }
        }
        return curr;
    }
};