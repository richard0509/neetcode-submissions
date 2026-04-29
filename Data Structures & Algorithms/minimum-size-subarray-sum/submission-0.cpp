class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int L = 0;
        int length = nums.size() + 1;
        int sum = 0;
        for (int R = 0; R < nums.size(); R++) {
            sum += nums[R];
            while (sum >= target) {
                length = std::min(length, R - L + 1);
                sum -= nums[L];
                L++;
            }
        }

        if (length == nums.size() + 1) {
            return 0;
        }
        return length;
    }
};