class Solution {
public:
	void rec_func(const string& digits, int index, string* curr_result, unordered_map<char, string>& h, vector<string>* result) {
		for (int i = 0; i < h[digits[index]].size(); ++i) {
			curr_result->at(index) = h[digits[index]][i];
			if (index + 1 == digits.size()) {
				result->push_back(*curr_result);
			}
			else {
				rec_func(digits, index + 1, curr_result, h, result);
			}
		}
	}
	vector<string> letterCombinations(string digits) {
		unordered_map<char, string> h;
		h['2'] = "abc";
		h['3'] = "def";
		h['4'] = "ghi";
		h['5'] = "jkl";
		h['6'] = "mno";
		h['7'] = "pqrs";
		h['8'] = "tuv";
		h['9'] = "wxyz";
		string curr_result(digits.size(), 'a');
		vector<string> result;
		rec_func(digits, 0, &curr_result, h, &result);
		return result;
	}
};