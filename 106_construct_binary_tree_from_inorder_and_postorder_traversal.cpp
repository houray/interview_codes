class Solution {
public:
    TreeNode* buildTreeImpl(vector<int>& inorder, vector<int>& postorder, int in_begin, int in_end, int po_begin, int po_end) {
        if (po_begin == po_end) {
            return NULL;
        }
        int value = postorder[po_end - 1];
        int in_idx;
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
        root->left = buildTreeImpl(inorder, postorder, in_begin, in_idx, po_begin, po_begin + in_idx - in_begin);
        root->right = buildTreeImpl(inorder, postorder, in_idx + 1, in_end, po_begin + in_idx - in_begin, po_end - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty()) { return NULL; }
        return buildTreeImpl(inorder, postorder, 0, inorder.size(), 0, postorder.size());
    }
};