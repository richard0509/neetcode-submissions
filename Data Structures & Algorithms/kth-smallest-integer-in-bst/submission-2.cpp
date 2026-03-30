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
    int ans;
    int count = 0;
public:
    int kthSmallest(TreeNode* root, int k) {
        DFS(root, k);
        return ans;
    }

    // inorder
    void DFS(TreeNode* root, int k) {
        if (count >= k) {
            return;
        }
        if (!root) {
            return;
        }
        DFS(root->left, k);
        if (count >= k) {
            return;
        }
        ans = root->val;
        count++;
        DFS(root->right, k);

    }
};
