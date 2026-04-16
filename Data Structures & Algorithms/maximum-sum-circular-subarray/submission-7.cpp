class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int min = nums[0];
        int min_sum = 0;
        int max = nums[0];
        int max_sum = 0;
        int total = 0;

        for (int i = 0; i < n; ++i) {
            total += nums[i];

            if (min_sum > 0) {
                min_sum = 0;
            }

            if (max_sum < 0) {
                max_sum = 0;
            }

            min_sum += nums[i];
            max_sum += nums[i];
            if (min_sum < min) {
                min = min_sum;
            }

            if (max_sum > max) {
                max = max_sum;
            }
        }


        int ans = (max < 0) ? max : std::max(max, total - min);

        return ans;
    }
};