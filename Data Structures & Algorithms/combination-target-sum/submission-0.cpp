class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int sum = 0;
        vector<vector<int>> ans;
        vector<int> sub;
        helper(nums, target, 0, sum, sub, ans);
        return ans;
    }

    void helper(std::vector<int>& nums, int target, int i, int sum, std::vector<int> sub, std::vector<std::vector<int>>& ans) {
        if (i >= nums.size()) {
            return;
        }
        if (sum == target) {
            ans.emplace_back(sub);
            return;
        } else if (sum > target) {
            return;
        }

        sub.emplace_back(nums[i]);
        sum += nums[i];
        helper(nums, target, i, sum, sub, ans);
        sub.pop_back();
        sum -= nums[i];
        helper(nums, target, i + 1, sum, sub, ans);
    }
};
