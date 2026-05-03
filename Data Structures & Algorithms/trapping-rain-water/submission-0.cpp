class Solution {
public:
    int trap(std::vector<int>& height)
    {
        int res = 0;
        int L = 0;
        int R = height.size() - 1;

        while (L < R) {
            int h = 0;
            if (height[L] > height[R]) {
                h = height[R];
                for (int i = L; i <= R; i++) {
                    if (h - height[i] > 0) {
                        res += h - height[i];
                        height[i] = h;
                    }
                }
                R--;
            }
            else {
                h = height[L];
                for (int i = L; i <= R; i++) {
                    if (h - height[i] > 0) {
                        res += h - height[i];
                        height[i] = h;
                    }
                }
                L++;
            }
        }
        return res;
    }
};