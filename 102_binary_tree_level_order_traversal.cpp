class Solution {
public:
    vector<vector<int>> result;
    void output(int level, TreeNode* node) {
        if (!node) { return; }
        if (result.size() == level) {
            result.push_back(vector<int>(1, node->val));
        } else {
            result[level].push_back(node->val);
        }
        output(level + 1, node->left);
        output(level + 1, node->right);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        output(0, root);
        return result;
    }
};