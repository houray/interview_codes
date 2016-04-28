class Solution {
public:
    bool check(TreeNode* left, TreeNode* right) {
        if (!left && !right) { return true; }
        else if (left && right) {
            return left->val == right->val && check(left->left, right->right) && check(left->right, right->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) { return true; }
        return check(root->left, root->right);
    }
};