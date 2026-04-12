class Solution {
public:
    int rob(vector<int>& nums) {
        // rob1, rob2, n
        int n = nums.size();
        int rob2 = 0;
        int rob1 = 0;
        for (int i = 0; i < n; ++i) {
            int temp = rob2;
            rob2 = std::max(nums[i] + rob1, rob2);
            rob1 = temp;
        }
        return rob2;
    }


};
