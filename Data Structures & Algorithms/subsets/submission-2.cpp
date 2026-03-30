class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        std::vector<int> subset;
        helper(nums, 0, subset, ans);
        return ans;

    }

    void helper(std::vector<int>& nums, int i, std::vector<int>& subset, std::vector<std::vector<int>>& ans) {
        if (i >= nums.size()) {
            ans.emplace_back(subset);
            return;
        }

        subset.emplace_back(nums[i]);
        helper(nums, i + 1, subset, ans);
        subset.pop_back();
        helper(nums, i + 1, subset, ans);
    }
};
