class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int unique_posi = 0; // how many unique number and unique number index
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[unique_posi]) {
                nums[unique_posi + 1] = nums[i]; 
                unique_posi++;
            }
        }
        return unique_posi + 1;
    }
};