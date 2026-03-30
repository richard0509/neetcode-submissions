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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return root;
        }

        if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else {
            if (!root->right) {
                return root->left;
            } else if (!root->left) {
                return root->right;
            } else {
                auto min = findMin(root->right);
                root->val = min->val;
                root->right = deleteNode(root->right, min->val);
            }
        }
        return root;
    }

    TreeNode* findMin(TreeNode* root) {
        auto cur = root;
        while (cur && cur->left) {
            cur = cur->left;
        }
        return cur;
    }
};