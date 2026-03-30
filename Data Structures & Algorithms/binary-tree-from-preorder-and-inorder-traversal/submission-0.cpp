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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) {
            return nullptr;
        }

        return solve(preorder, 0, preorder.size() - 1,
                    inorder, 0, inorder.size() - 1);
    }

    TreeNode* solve(std::vector<int>& preorder,int pre_s, int pre_e,
                    std::vector<int>& inorder, int in_s, int in_e) {
        if (pre_s > pre_e) {
            return nullptr;
        }
        int k = findInorderIndex(inorder, preorder[pre_s]);
        int num_left = k - in_s;
        TreeNode* root = new TreeNode(preorder[pre_s]);
        root->left = solve(preorder, pre_s + 1, pre_s + num_left,
                            inorder, in_s, k - 1);
        root->right = solve(preorder, pre_s + num_left + 1, pre_e,
                            inorder, k + 1, in_e);

        return root;
    }

    int findInorderIndex(std::vector<int>& inorder, int val) {
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == val) {
                return i;
            }
        }
        // not found return -1
        return -1;
    }
};
