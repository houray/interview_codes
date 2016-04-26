class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (!nums.size()) {
            return 0;
        }
        int begin = 0;
        int end = nums.size() - 1;
        while (begin < end) {
            int mid = begin + (end - begin) / 2;
            if (nums[mid] < target) {
                begin = mid + 1;
            } else {
                end = mid;
            }
        }
        if (nums[begin] < target) {
            return begin + 1;
        } else {
            return begin;
        }
    }
};
