class Solution {
public:
    int trap(std::vector<int>& height)
    {
        int res = 0;
        int L = 0;
        int R = height.size() - 1;

        int max_l = height[L];
        int max_r = height[R];

        while (L < R) {
            int h = 0;
            if (max_l > max_r) {
                h = std::min(max_l, max_r);
                if (h - height[R] > 0) {
                    res += h - height[R];
                }
                R--;
                max_r = std::max(height[R], max_r);
            }
            else {
                h = std::min(max_l, max_r);
                if (h - height[L] > 0) {
                    res += h - height[L];
                }
                L++;
                max_l = std::max(height[L], max_l);
            }
        }
        return res;
    }
};
