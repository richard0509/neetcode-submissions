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
            if (max_l > max_r) {
                R--;
                max_r = std::max(height[R], max_r);
                res += max_r - height[R];
            }
            else {
                L++;
                max_l = std::max(height[L], max_l);
                res += max_l - height[L];
            }
        }
        return res;
    }
};
