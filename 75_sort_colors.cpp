class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int n = nums.size() - 1;
        while (j <= n) {
            if (!nums[j]) {
                swap(nums[i], nums[j]);
                ++i;
                ++j;
            } else if (nums[j] == 1){
                ++j;
            } else {
                swap(nums[n], nums[j]);
                --n;
            }
        }
    }
};