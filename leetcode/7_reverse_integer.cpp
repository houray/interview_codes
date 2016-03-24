// Watch out when reverse of x is exceeded the integer limit.
class Solution {
public:
    int reverse(int x) {
  if (x == -2147483648)
    return 0;
  int result = 0;
  int flag = x >= 0 ? 1 : -1;
  x = x > 0 ? x : -x;
  while (x / 10 > 0) {
    result = result * 10 + x % 10;
    x = x / 10;
  }
  if (214748364 - result < 0 )
    return 0;
  if (214748364 - result == 0 && x % 10 > 1)
    return 0;
  result = result * 10 + x % 10;
  return result * flag;
    }
};
