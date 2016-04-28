class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (root) {
        queue<TreeNode*>* curr = new queue<TreeNode*>;
        queue<TreeNode*>* prev = new queue<TreeNode*>;
        curr->push(root);
        while (!curr->empty()) {
            swap(curr, prev);
            vector<int> curr_row;
            while(!prev->empty()) {
                curr_row.push_back(prev->front()->val);
                if (prev->front()->left != NULL) {
                    curr->push(prev->front()->left);
                }
                if (prev->front()->right != NULL) {
                    curr->push(prev->front()->right);
                }
                prev->pop();
            }
            if (!curr_row.empty()) {
                result.insert(result.begin(), curr_row);
            }
        }
        }
        return result;
    }
};