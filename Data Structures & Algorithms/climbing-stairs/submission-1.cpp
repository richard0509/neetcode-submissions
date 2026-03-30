class Solution {
private:
    std::vector<int> store;

public:
    int climbStairs(int n) {
        if (store.empty()) {
            store.assign(n + 1, -1);
        }
        if (n <= 1) {
            if (store[n] == -1) {
                store[n] = 1;
            }
            return 1;
        }

        if (store[n] == -1) {
            store[n] = climbStairs(n - 1) + climbStairs(n - 2);
        } else {
            return store[n];
        }
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};
