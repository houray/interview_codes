class Solution {
public:
	int trap(vector<int>& height) {
		if (height.size() < 2) {
			return 0;
		}
		int curr_peak = height[0];
		vector<int> water_level(height.size(), 0);
		for (int i = 1; i < height.size(); ++i) {
			if (height[i] < curr_peak) {
				water_level[i] = curr_peak - height[i];
			}
			else {
				curr_peak = height[i];
			}
		}
		int result = 0;
		curr_peak = height[height.size() - 1];
		for (int i = height.size() - 1; i >= 0; --i) {
			if (height[i] < curr_peak) {
				water_level[i] = curr_peak - height[i] > water_level[i] ? water_level[i] : curr_peak - height[i];
				result += water_level[i];
			}
			else {
				curr_peak = height[i];
				water_level[i] = 0;
			}
		}
		return result;
	}
};