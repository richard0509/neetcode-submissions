class Solution {
public:
    int rob(vector<int>& nums) {
        // rob1, rob2, n
        int n = nums.size();
        int rob2 = 0;
        int rob1 = 0;
        for (int i = nums.size() - 1; i >= 0; --i) {
            int temp = rob1;
            rob1 = std::max(nums[i] + rob2, rob1);
            rob2 = temp;
        }
        return rob1;
    }


};
