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
    std::vector<int> ans;
public:
    int kthSmallest(TreeNode* root, int k) {
        DFS(root, k);
        return ans[k - 1];
    }

    // inorder
    void DFS(TreeNode* root, int k) {
        if (ans.size() >= k) {
            return;
        }
        if (!root) {
            return;
        }
        DFS(root->left, k);
        ans.emplace_back(root->val);
        DFS(root->right, k);

    }
};
