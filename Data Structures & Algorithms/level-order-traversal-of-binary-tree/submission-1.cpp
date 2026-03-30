/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::queue<TreeNode*> q;
        std::vector<std::vector<int>> ans;

        if (root) {
            q.push(root);
        }    

        int level = 0;
        while (q.size() > 0) {
            std::vector<int> sub_ans;
            int length = q.size();
            for (int i = 0; i < length; i++) {
                auto temp = q.front();
                q.pop();
                int val = temp->val;
                sub_ans.emplace_back(val);
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }
            ans.emplace_back(sub_ans);
            level++;
        }

        return ans;
    }
};
