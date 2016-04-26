class Solution {
public:
    // Find rotate point.
int rotate(vector<int>& nums, int a, int b) {
    int m = (b - a) / 2 + a;
    if (m == b) {
        return m;
    }
    if (m == a) {
        if (nums[a] > nums[a + 1]) {
            return a;
        } else {
            return a + 1;
        }
    }
    if (nums[m - 1] < nums[m] && nums[m] > nums[m + 1]) {
        return m;
    }
    if (nums[m] > nums[0]) {
        return rotate(nums, m + 1, b);
    } else {
        return rotate(nums, a, m - 1 > a ? m - 1 : a);
    }
}
int search(vector<int>& nums, int a, int b, int target) {
    int m = (b - a) / 2 + a;
    if (nums[m] == target) {
        return m;
    }
    if (a == b) {
        return -1;
    }
    if (nums[m] > target) {
        return search(nums, a, m - 1 > a ? m - 1 : a, target);
    } else {
        return search(nums, m + 1, b, target);
    }
}
int search(vector<int>& nums, int target) {
    if (nums.size() < 1)
    return -1;
    if (nums.size() == 1)
    return nums[0] == target ? 0 : -1;
    int l = nums.size();
    if (nums[0] < nums[l - 1]) {
        return search(nums, 0, l - 1, target);
    }
    int m = rotate(nums, 0, l - 1);
    if (target >= nums[0]) {
        return search(nums, 0, m, target);
    } else {
        return search(nums, m + 1, l -1, target);
    }
}
};
