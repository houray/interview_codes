class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) { return 0;}
        set<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            s.insert(nums[i]);
        }
        set<int>::iterator it = s.begin();
        int next = (*s.begin()) + 1;
        int l = 1;
        int max = 1;
        for (++it; it != s.end(); ++it) {
            if (*it == next) {
                ++l;
                ++next;
                max = max > l ? max : l;
            } else {
                l = 1;
                next = (*it) + 1;
            }
        }
        return max;
    }
};