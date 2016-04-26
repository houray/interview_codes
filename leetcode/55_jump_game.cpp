class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> result(nums.size(), false);
        result[0] = true;
        int begin = 0; int end = 1;
        while (begin < nums.size() && end < nums.size()) {
            if (!result[begin]) {
                break;
            }
            while (end - begin <= nums[begin] && end < nums.size()) {
                result[end] = true;
                ++end;
            }
            ++begin;
        }
        return result[nums.size() - 1];
    }
};
