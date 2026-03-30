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
private:
    bool ans = true;

public:
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }

        if (traversal(root->left) == -1 || traversal(root->right) == -1) {
            return false;
        }
        
        if (traversal(root->left) > traversal(root->right)) {
            return traversal(root->left) - traversal(root->right) <= 1;
        } else {
            return traversal(root->right) - traversal(root->left) <= 1;
        }
    }

    int traversal(TreeNode* root) {
        int lh = 0;
        int rh = 0;
        if (!root) {
            return 0;
        }

        lh = traversal(root->left);
        rh = traversal(root->right);

        if (lh == -1 || rh == -1) {
            return -1;
        }

        if (lh - rh >= 2) {
            return -1;
        } else if (rh - lh >= 2) {
            return -1;
        }

        if (lh > rh) {
            return lh + 1;
        } else {
            return rh + 1;
        }

    }
};
