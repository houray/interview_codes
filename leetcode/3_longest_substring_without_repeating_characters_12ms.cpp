class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256] = {0};
        int len = s.size();
        if (len <= 0)
            return 0;
        int maxLen = -1, curLen = 0, startPos = 0;
        for (int i = 0; i < len; ++ i) {
            char c = s[i];
            if (hash[c] != 0) {
				if (hash[c] - 1 > startPos)
					startPos = hash[c] - 1;
                curLen = i - startPos;
            }else
                curLen ++;
            hash[c] = i + 1;
            if (curLen > maxLen)
                maxLen = curLen;
        }
        return maxLen;
    }
};
