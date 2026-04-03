class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> maps;
        for (int i = 0; i < nums.size(); ++i) {
            if (maps.count(target - nums[i])) {
                return std::vector<int>{maps[target - nums[i]], i};
            }
            maps[nums[i]] = i;
        }

    }
};
