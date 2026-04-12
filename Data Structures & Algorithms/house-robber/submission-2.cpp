class Solution {
public:
    int rob(vector<int>& nums) {
        std::vector<int> cache(nums.size(), -1);

        int i = 0;
        return dfs(nums, 0, cache);
    }

    int dfs(std::vector<int>& nums, int index, std::vector<int>& cache) {
        if (index >= nums.size()) {
            return 0;
        }

        if (cache[index] != -1) {
            return cache[index];
        }

        cache[index] = std::max(nums[index] + dfs(nums, index + 2, cache), dfs(nums, index + 1, cache));
        return cache[index];

    }
};
