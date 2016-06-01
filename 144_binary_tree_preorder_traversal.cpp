class Solution {
public:
    vector<int> result;
    void preorder(TreeNode* root) {
        if (!root) { return; }
        result.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return result;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> result;
        if (root) { s.push(root); }
        while(!s.empty()) {
            TreeNode* curr = s.top();
            result.push_back(curr->val);
            s.pop();
            if (curr->right != NULL) { s.push(curr->right); }
            if (curr->left != NULL) { s.push(curr->left); }
        }
        return result;
    }
};