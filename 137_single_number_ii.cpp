class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        int bit = 1;
        int positive = 0;
        for (int i = 0; i < nums.size(); ++i) {
            positive += (nums[i] >= 0 ? 1 : 0);
            // nums[i] = nums[i] >= 0 ? nums[i] : -nums[i];
        }
        positive = positive % 3 > 0 ? 1 : -1;
        while (1) {
            bool non_zero = false;
            int bit_sum = 0;
            for (int i = 0; i < nums.size(); ++i) {
                int q = nums[i] % 3;
                bit_sum += (q >= 0 ? q : -q);
                nums[i] = nums[i] / 3;
                non_zero = non_zero || nums[i] != 0;
            }
            cout << bit_sum << endl;
            result += (bit_sum % 3) * bit;
            bit *= 3;
            if (!non_zero) { break; }
        }
        return result * positive;
    }
};