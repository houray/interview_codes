class Solution {
public:
    void RecFunc(vector<int>* result, TreeNode* node) {
        if (node->left) {
            RecFunc(result, node->left);
        }
        result->push_back(node->val);
        if (node->right) {
            RecFunc(result, node->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root) {
            RecFunc(&result, root);
        }
        return result;
    }
};