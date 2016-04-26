class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums[0] == 0)
            return 0;
        vector<int> result(nums.size(), 0);
        int source = 0;
        int target = 1;
        while (target < nums.size()) {
            while (target <= (source + nums[source] < nums.size() - 1 ? source + nums[source] : nums.size() - 1) ) {
                result[target] = result[source] + 1; cout << result[target] << endl;
                ++target;
            }
            ++source;
        }
        return result[nums.size() - 1];
    }
};