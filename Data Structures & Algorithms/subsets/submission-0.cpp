class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        ans.emplace_back();
        for (int num : nums) {
            int size = ans.size();
            for (int i = 0; i < size; i++) {
                auto temp = ans[i];
                temp.emplace_back(num);
                ans.emplace_back(temp);
            }
        }
        return ans;
    }
};
