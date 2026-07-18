class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            auto it = s.find(nums[i]);
            if (it == s.end()) {
                s.insert(nums[i]);
            } else {
                s.erase(nums[i]);
            }
        }
        return *s.begin();
    }
};
