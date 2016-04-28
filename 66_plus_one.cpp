class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int flag = 1;
        for (int i = digits.size() - 1; i > -1; --i) {
            int tmp = digits[i] + flag;
            flag = tmp / 10;
            digits[i] = tmp % 10;
        }
        if (flag) {
            digits.insert(digits.begin(), flag);
        }
        return digits;
    }
};