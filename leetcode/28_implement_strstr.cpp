class Solution {
public:
std::vector<int> prefix(std::string& M) {
  std::vector<int> prefix = std::vector<int>(M.size(), -1);
  int curr_prefix = -1;
  for (unsigned int i = 1; i < M.size(); ++i) {
    while (curr_prefix > -1 && M[curr_prefix + 1] != M[i]) {
      curr_prefix = prefix[curr_prefix];
    }
    if (M[curr_prefix + 1] == M[i]) {
      ++curr_prefix;
    }
    prefix[i] = curr_prefix;
  }
  return prefix;
}
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        vector<int> pre = prefix(needle);
        int curr_match = -1;
        for (int i = 0; i < haystack.size(); ++i) {
            cout<< i << ", " << curr_match<<endl;
            while (curr_match > -1 && needle[curr_match + 1] != haystack[i]) {
                curr_match = pre[curr_match];
            }
            if (needle[curr_match + 1] == haystack[i]) {
                ++curr_match;
                if (curr_match + 1 == needle.size()){
                    return i - curr_match;
                }
            }
        }
        return -1;
    }
};
