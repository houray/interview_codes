// O(n) time solution.
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;
        while (left < right) {
            int currArea = (right - left) * (height[left] < height[right] ? height[left] : height[right]);
            maxArea = maxArea > currArea ? maxArea : currArea;
            if (height[left] < height[right])
                ++left;
            else
                --right;
        }
        return maxArea;
    }
};
