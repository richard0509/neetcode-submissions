class Solution {
public:
    vector<int> countBits(int n) {
        std::vector<int> res;
        for (int i = 0; i <= n; i++) {
            int count = 0;
            int j = i;
            while (j > 0) {
                if (j & 1 == 1) {
                    count++;
                }
                j = j >> 1;
            }
            res.emplace_back(count);
        }
        return res;
    }
};
