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
    vector<int> rightSideView(TreeNode* root) {
        std::queue<TreeNode*> q;
        std::vector<int> ans;

        if (root) {
            q.push(root);
        }

        // level traversal
        while (q.size() > 0) {
            int length = q.size();
            // breadth traversal
            for (int i = 0; i < length; i++) {
                auto temp = q.front();
                q.pop();
                if (i == length - 1) {
                    ans.emplace_back(temp->val);
                }
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }
        }

        return ans;
    }
};
