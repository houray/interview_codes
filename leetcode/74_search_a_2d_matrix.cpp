class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int first = 0; 
        int last = matrix.size() - 1;
        int mid = first + (last - first) / 2;
        while (last - first > 1) {
            if (matrix[mid][0] < target) {
                first = mid;
                mid = first + (last - first) / 2;
            } else if (matrix[mid][0] > target) {
                last = mid - 1;
                mid = first + (last - first) / 2;
            } else {
                return true;
            }
        }
        int row = target < matrix[last][0] ? mid : last; 
        first = 0;
        last = matrix[0].size() - 1;
        mid = first + (last - first) / 2;

        while (last - first > 1) {
            if (matrix[row][mid] < target) {
                first = mid;
                mid = first + (last - first) / 2;
            } else if (matrix[row][mid] > target) {
                last = mid - 1;
                mid = first + (last - first) / 2;
            } else {
                return true;
            }
        }
        if (matrix[row][first] == target || matrix[row][last] == target) {
            return true;
        }
        return false;
    }
};
