class Solution {
public:
    int sum;
    void sumNumbersImpl(TreeNode* root) {
        if (!root) { return; }
        if (root->left != NULL) {
            root->left->val += (root->val * 10);
            sumNumbersImpl(root->left);
        }
        if (root->right != NULL) {
            root->right->val += (root->val * 10);
            sumNumbersImpl(root->right);
        }
        if (root->left == NULL && root->right == NULL) {
            sum += root->val;
        }
    }
    int sumNumbers(TreeNode* root) {
        sum = 0;
        sumNumbersImpl(root);
        return sum;
    }
};