class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        // rob1, rob2, n
        std::vector<int> cache(nums.size());
        int n = nums.size();
        cache[n - 1] = nums[n - 1];
        cache[n - 2] = std::max(nums[n - 1], nums[n - 2]);
        for (int i = nums.size() - 3; i >= 0; --i) {
            cache[i] = std::max(nums[i] + cache[i + 2], cache[i + 1]);
        }
        return cache[0];
    }


};
