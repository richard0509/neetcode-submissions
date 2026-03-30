class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (!count(ans.begin(), ans.end(), nums[i])) {
                ans.push_back(nums[i]);
            }
        }    
        nums = ans;
        return ans.size();
    }
};