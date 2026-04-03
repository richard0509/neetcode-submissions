class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> sets;
        for (int num : nums) {
            if (sets.count(num)) {
                return true;
            }
            sets.insert(num);
        }
        return false;
    }
};