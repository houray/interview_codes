class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3) {
            return nums.size();
        }
        int curr_num = nums[0];
        int curr_count = 0;
        int i = 1;
        int j = 1;
        while (j < nums.size()) {
            if (nums[j] == curr_num) {
                if (!curr_count) {
                    curr_count = 1;
                    nums[i] = nums[j];
                    ++i;
                }
            } else {
                nums[i] = nums[j];
                curr_num = nums[i];
                curr_count = 0;
                ++i;
            }
            ++j;
        }
        return i;
    }
};