class Solution {
    std::vector<int> cache;
public:
    int climbStairs(int n) {
        
        if (n <= 1) {
            return 1;
        }

        if (cache.empty()) {
            cache.assign(n + 1, -1);
        }

        if (cache[n] != -1) {
            return cache[n];
        }

        cache[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return cache[n];
        
    }
};
