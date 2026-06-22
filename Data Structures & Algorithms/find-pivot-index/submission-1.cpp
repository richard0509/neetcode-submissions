class Solution {
    std::vector<int> prefix;
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];
            prefix.emplace_back(total);
        }

        for (int i = 0; i < prefix.size(); i++) {
            int left_sum = i > 0 ? prefix[i - 1] : 0;
            int right_sum = rangeSum(i + 1, prefix.size() - 1);
            if (left_sum == right_sum) {
                return i;
            }
        }
        return -1;
    }

    // include left
    int rangeSum(int left, int right) {
        int pre_right = prefix[right];
        int pre_left = left > 0 ? prefix[left - 1] : 0;
        return pre_right - pre_left;
    }
};