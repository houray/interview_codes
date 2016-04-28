class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        int max_diff = prices[1] - prices[0];
        int min = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            min = min < prices[i] ? min : prices[i];
            int curr = prices[i] - min;
            max_diff = max_diff > curr ? max_diff : curr;
        }
        return max_diff > 0 ? max_diff : 0;
    }
};