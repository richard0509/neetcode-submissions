class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> maps;
        for (int num : nums) {
            maps[num]++;
        }
        
        for (int num : nums) {
            if (maps[num] > 1) {
                return true;
            }
        }
        return false;
    }
};