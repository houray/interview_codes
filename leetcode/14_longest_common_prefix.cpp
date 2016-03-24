class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        int max_prefix = strs[0].size();
        int curr_string = 1;
        while (curr_string < strs.size()) {
            int curr_prefix = 0;
            while (curr_prefix < max_prefix && curr_prefix < strs[curr_string].size() && strs[0][curr_prefix] == strs[curr_string][curr_prefix]) {
                ++curr_prefix;
            }
            max_prefix = curr_prefix;
            ++curr_string;
        }
        if (max_prefix > 0)
            return strs[0].substr(0, max_prefix);
        else
            return "";
    }
};
