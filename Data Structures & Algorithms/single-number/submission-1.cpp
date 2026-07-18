class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int it = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            it ^= nums[i];
        }
        return it;
    }
};
