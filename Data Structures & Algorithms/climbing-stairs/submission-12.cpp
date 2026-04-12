class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> cache = {1, 1};

        int i = 2;
        while (i <= n) {
            int temp = cache[1];
            cache[1] = cache[0] + cache[1];
            cache[0] = temp;
            i++;
        }
        return cache[1];
    }
};
