class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> prefix;
        int prod = 1;
        for (int i = 0; i < nums.size(); i++) {
            prefix.emplace_back(prod);
            prod *= nums[i];
        }

        prod = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            prefix[i] *= prod;
            prod *= nums[i];
        }

        return prefix;
    }
};
