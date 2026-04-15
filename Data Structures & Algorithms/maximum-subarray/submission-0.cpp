class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0];
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0;
            for (int j = i; j < nums.size(); ++j) {
                sum += nums[j];
                if (sum > max) {
                    max = sum;
                }
            }
        }

        return max;
    }
};
