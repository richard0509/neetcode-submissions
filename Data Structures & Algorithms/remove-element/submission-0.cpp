class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int posi = 0; // next position to store number and the numbers of elements
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[posi] = nums[i];
                posi++;
            }
        }
        return posi;
    }
};