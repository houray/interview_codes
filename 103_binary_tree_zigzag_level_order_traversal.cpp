class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        stack<TreeNode*> curr;
        stack<TreeNode*> prev;
        bool inverse = true;
        curr.push(root);
        while (!curr.empty()) {
            vector<int> digits;
            prev = curr;
            while (!curr.empty()) {
                curr.pop();
            }
            inverse = !inverse;
            while(!prev.empty()) {
                if (prev.top()) {
                    digits.push_back(prev.top()->val);
                    if (inverse) {
                        curr.push(prev.top()->right);
                        curr.push(prev.top()->left);
                    } else {
                        curr.push(prev.top()->left);
                        curr.push(prev.top()->right);
                    }
                }
                prev.pop();
            }
            if (!digits.empty())
            result.push_back(digits);
        }
        return result;
    }
};