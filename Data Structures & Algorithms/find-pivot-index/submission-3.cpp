class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        for (int i = 0; i < n; i++) {
            int left = prefix[i];
            int right = prefix[n] - prefix[i + 1];
            if (left == right) {
                return i;
            }
        }
        return -1;
    }
};