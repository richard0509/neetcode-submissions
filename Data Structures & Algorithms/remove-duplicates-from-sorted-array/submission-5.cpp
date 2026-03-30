class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int unique_posi = 1; // how many unique number and unique number index
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[unique_posi] = nums[i]; 
                unique_posi++;
            }
        }
        return unique_posi;
    }
};