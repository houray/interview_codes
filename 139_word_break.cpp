class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if (s.length() < 1) { return false; }
        vector<bool> valid(s.length() + 1, false);
        valid[0] = true;
        
        for (int i = 0; i < s.length(); ++i) {
            if (!valid[i]) { continue; }
            for (auto& word : wordDict) {
                int l = word.size();
                if (valid[i + l] || i + l > s.length()) { continue; }
                valid[i + l] = (s.substr(i, l) == word);
            }
        }
        return valid[s.length()];
    }
};