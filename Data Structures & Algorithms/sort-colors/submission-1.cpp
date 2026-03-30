class Solution {
public:
    // bucket sort
    void sortColors(vector<int>& nums) {
        int count[3] = {0};
        for (int num : nums) {
            count[num]++;
        }

        int i = 0;
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < count[j]; k++) {
                nums[i] = j;
                i++;
            }
        }
        
    }
};