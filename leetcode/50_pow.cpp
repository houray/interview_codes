class Solution {
public:
    double myPow(double x, int n) {
    x = (n > 0) ? x : 1 / x;
    double ans = 1;
    for (double y = x; n != 0; n /= 2) {
        if (n % 2 != 0) ans *= y;
        y *= y;
    }
    return ans;
    }
};