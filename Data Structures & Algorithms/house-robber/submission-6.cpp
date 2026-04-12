class Solution {
public:
    int rob(vector<int>& nums) {
        // rob1, rob2, n
        int n = nums.size();
        int rob2 = nums[n - 1];
        int rob1 = std::max(nums[n - 1], nums[n - 2]);
        for (int i = nums.size() - 3; i >= 0; --i) {
            int temp = rob1;
            rob1 = std::max(nums[i] + rob2, rob1);
            rob2 = temp;
        }
        return rob1;
    }


};
