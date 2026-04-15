class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int max = nums[0];
        int sum = 0;

        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0;
            for (int j = i; j < nums.size() + i; ++j) {
                sum += nums[j % n];
                if (sum > max) {
                    max = sum;
                }
            }
        }

        return max;
    }
};