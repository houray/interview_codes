class Solution {
public:
	bool isValid(string s) {
		stack<char> st;
		int index = 0;
		while (index < s.size()) {
			if (s[index] == '(' || s[index] == '[' || s[index] == '{') {
				st.push(s[index]);
			}
			if (s[index] == ')') {
				if (!st.empty() && st.top() == '(') {
					st.pop();
				}
				else {
					return false;
				}
			}
			if (s[index] == ']') {
				if (!st.empty() && st.top() == '[') {
					st.pop();
				}
				else {
					return false;
				}
			}
			if (s[index] == '}') {
				if (!st.empty() && st.top() == '{') {
					st.pop();
				}
				else {
					return false;
				}
			}
			++index;
		}
		return st.empty();
	}
};