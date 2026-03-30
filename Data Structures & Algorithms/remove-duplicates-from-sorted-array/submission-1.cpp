class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        for (int i = 1; i < nums.size(); i++) {
            bool is_duplicate = false;
            for (int j = 0; j < i; j++) {
                if (nums[j] == nums[i]) {
                    is_duplicate = true;
                    break;
                }
            }

            if(!is_duplicate) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};