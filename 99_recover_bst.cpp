class Solution {
public:
    void recoverNode(TreeNode* node, TreeNode* min, TreeNode* max) {
        if (!node) {
            return;
        }
        if (node->val < min->val) {
            int t = min->val;
            min->val = node->val;
            node->val = t;
        } else if (node->val > max->val) {
            int t = max->val;
            max->val = node->val;
            node->val = t;
        } else {
            recoverNode(node->left, min, node);
            recoverNode(node->right, node, max);
        }
    }
    bool isBST(TreeNode* node, long long min, long long max) {
        if (!node) { return true; }
        return (node->val < max && node->val > min && isBST(node->left, min, node->val) && isBST(node->right, node->val, max));
    }
    void recoverTree(TreeNode* root) {
        TreeNode* min= new TreeNode(-2147483648);
        TreeNode* max= new TreeNode(2147483647);
        while (!isBST(root, -2147483649, 2147483648))
            recoverNode(root, min, max);
    }
};