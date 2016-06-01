class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        int positive = 1;
        int bit = 0;
        for (int i = 0; i < nums.size(); ++i) {
            positive *= (nums[i] >= 0 ? 1 : -1);
            nums[i] = nums[i] >= 0 ? nums[i] : -nums[i];
        }
        while(1) {
            int bit_sum = 0;
            bool non_zero = false;
            for (int i = 0; i < nums.size(); ++i) {
                non_zero = non_zero || (nums[i] > 0);
                bit_sum = (nums[i] & 0x01) ^ bit_sum;
                nums[i] = nums[i] >> 1;
            }
            result += (bit_sum & 0x01) << bit;
            ++bit;
            if (!non_zero) { break; }
        }
        return result * positive;
    }
};