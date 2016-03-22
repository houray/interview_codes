class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> h;
        int max_len = 0;
        int curr_len = 0;
        for (int i = 0; i < s.size(); ++i) {
            unordered_map<char, int>::iterator it;
            it = h.find(s[i]);
            if(it != h.end() && i - it->second <= curr_len) {
                curr_len = i - it->second;
            } else {
                ++curr_len;
            }
            h[s[i]] = i;
            max_len = max(curr_len, max_len);
        }
        return max_len;
    }
};
