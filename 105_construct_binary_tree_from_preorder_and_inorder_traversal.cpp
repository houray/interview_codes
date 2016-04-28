class Solution {
public:
    TreeNode* buildTreeImpl(vector<int>& preorder, vector<int>& inorder, int pre_begin, int pre_end, int in_begin, int in_end) {
        if (pre_begin == pre_end) { return NULL; }
        int value = preorder[pre_begin];
        int in_idx = -1;
        for (int i = in_begin, j = in_end - 1; i <= j; ++i, --j) {
            if (inorder[i] == value) {
                in_idx = i;
                break;
            }
            if (inorder[j] == value) {
                in_idx = j;
                break;
            }
        }
        TreeNode* root = new TreeNode(value);
        root->left = buildTreeImpl(preorder, inorder, pre_begin + 1, pre_begin + 1 + in_idx - in_begin, in_begin, in_idx);
        root->right = buildTreeImpl(preorder, inorder, pre_begin + 1 + in_idx - in_begin, pre_end, in_idx + 1, in_end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) { return NULL; }
        return buildTreeImpl(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }
};