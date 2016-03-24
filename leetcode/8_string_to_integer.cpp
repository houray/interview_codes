// Take much more time to consider the rare cases. Bad question!
class Solution {
public:
    int myAtoi(string str) {
        int flag = 0;
        int i = 0;
        int result = 0;
        if (str[i] > 58)
            return result;
        while (i < str.size()) {
            if (str[i] > 57)
            return result;
            if (flag == 0) {
                if (str[i] - '0' >= 0 && str[i] - '0' < 10) {
                    flag = 1;
                    result = str[i] - '0';
                }
                if (str[i] == '-') {
                    flag = -1;
                }
                if (str[i] == '+') {
                    flag = 1;
                }
                ++i;
                continue;
            }
            if (str[i] == '-' || str[i] == '+')
                return 0;
            if (str[i] - '0' >= 0 && str[i] - '0' < 10) {
                if (flag == 1 && 214748364 - result < 0)
                    return 2147483647;
                if (flag == -1 && 214748364 + result < 0)
                    return -2147483648;
                if (214748364 - result == 0 || 214748364 + result == 0 ) {
                    if (flag == 1 && str[i] - '0' > 7)
                    return 2147483647;
                    if (flag == -1 && str[i] - '0' > 8)
                    return -2147483648;
                } 
                result = result * 10 + (str[i] - '0') * flag;
            } else if (str[i] != ',') {
                return result;
            }
            ++i;
        }
        return result;
    }
};
