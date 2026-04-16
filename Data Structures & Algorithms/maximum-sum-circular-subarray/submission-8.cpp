class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        int max = nums[0];
        int min = nums[0];

        int max_sum = 0;
        int min_sum = 0;

        int total = 0;

        for (int i = 0; i < n; ++i) {
            total += nums[i];
            
            if (max_sum < 0) {
                max_sum = 0;
            }
            if (min_sum > 0) {
                min_sum = 0;
            }

            max_sum += nums[i];
            min_sum += nums[i];

            if (max_sum > max) {
                max = max_sum;
            }
            if (min_sum < min) {
                min = min_sum;
            }
        }

        if (max < 0) {
            return max;
        }

        return std::max(max, total - min);
    }
};