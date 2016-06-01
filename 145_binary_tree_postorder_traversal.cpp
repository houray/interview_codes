class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> result;
        if (root) { s.push(root); }
        TreeNode* prev = NULL;
        while (!s.empty()) {
            TreeNode* curr = s.top();
            if ((curr->left == NULL && curr->right == NULL) || (prev != NULL && (prev == curr->left || prev == curr->right))) {
                result.push_back(curr->val);
                s.pop();
                prev = curr;
            } else {
                if (curr->right != NULL) {s.push(curr->right);}
                if (curr->left != NULL) {s.push(curr->left);}
            }
        }
        return result;
    }
};