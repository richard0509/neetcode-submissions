class Solution {
public:
    vector<int> countBits(int n) {
        std::vector<int> res;
        for (int i = 0; i <= n; ++i) {
            int count = 0;
            int n = i;
            while (n > 0) {
                if ((n & 1) == 1) {
                    count++;
                }
                n = n >> 1;
            }
            res.emplace_back(count);
        }
        return res;
    }
};
