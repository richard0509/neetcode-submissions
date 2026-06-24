class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        freq[0] = 1;
        int sum = 0;
        int count = 0;
        for (int num : nums) {
            sum += num;
            int diff = sum - k;
            count += freq[diff];
            freq[sum]++;
        }
        return count;
    }
};