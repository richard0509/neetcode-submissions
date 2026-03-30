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
    int kthSmallest(TreeNode* root, int k) {
        int count = k;
        int ans = 0;
        DFS(root, count, ans);
        return ans;
    }

    // inorder
    void DFS(TreeNode* root, int& count, int& ans) {
        if (!root) {
            return;
        }
        DFS(root->left, count, ans);
        count--;
        if (count == 0) {
            ans = root->val;
            return;
        }
        DFS(root->right, count, ans);

    }
};
