class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res = 0;
        int pos = 31;
        while (n > 0) {
            if ((n & 1) == 1) {
                int num = 1;
                for (int i = 0; i < pos; ++i) {
                    num = num << 1;
                }
                res += num;
            }
            n = n >> 1;
            pos--;
        }
        return res;
    }
};
