
class Solution {
public:
    int maxArea(std::vector<int>& height)
    {
        int L = 0;
        int R = height.size() - 1;
        int res = std::min(height[L], height[R]) * (R - L);

        while (L < R) {
            if (height[L] > height[R]) {
                R--;
                res = std::max(std::min(height[L], height[R]) * (R - L), res);
            }
            else {
                L++;
                res = std::max(std::min(height[L], height[R]) * (R - L), res);
            }
        }

        return res;
    }
};