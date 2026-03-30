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
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }

        return traversal(root) != -1;

    }

    int traversal(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int lh = 0;
        int rh = 0;

        lh = traversal(root->left);
        if (lh == -1) {
            return -1;
        }

        rh = traversal(root->right);
        if (rh == -1) {
            return -1;
        }

        if (std::abs(lh - rh) > 1) {
            return -1;
        }

        return std::max(lh, rh) + 1;

    }
};
