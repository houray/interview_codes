class Solution {
public:
    TreeNode* sortedArrayToBSTImpl(vector<int>& nums, int begin, int end) {
        if (end == begin) {
            return NULL;
        }
        int mid = begin +  (end - 1 - begin) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBSTImpl(nums, begin, mid);
        root->right = sortedArrayToBSTImpl(nums, mid + 1, end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) { return NULL; }
        return sortedArrayToBSTImpl(nums, 0, nums.size());
    }
};