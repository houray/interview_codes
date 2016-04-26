class Solution {
public:
    int lengthOfLastWord(string s) {
        size_t pos = s.rfind(" ");
        int end = s.size() - 1;
        if (pos == string::npos) {
            return s.size();
        }
        cout << pos << ", " <<end <<endl;
        while (end >= 0 && pos == end) {
            --end;
            pos = s.rfind(" ", end);
            cout << pos << ", " <<end <<endl;
        }
        return end >= 0 ? end - pos : 0;
    }
};
