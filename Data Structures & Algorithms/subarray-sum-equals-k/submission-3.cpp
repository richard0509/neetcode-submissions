class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<int> prefix(n + 1, 0);
        std::unordered_map<int, int> freq;
        freq[0] = 1;
        int count = 0;

        int prefix_sum = 0;
        for (int i = 1; i < n + 1; i++) {
            prefix_sum += nums[i - 1];
            prefix[i] = prefix_sum;
            if (freq[prefix[i] - k] != 0) {
                count += freq[prefix[i] - k];
            }
            freq[prefix[i]]++;
        }

        return count;
    }
};