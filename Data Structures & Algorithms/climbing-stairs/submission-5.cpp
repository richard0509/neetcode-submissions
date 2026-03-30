class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        int prev2 = 1;
        int prev1 = 2;
        int curr = 0;

        for (int i = 0; i < n - 2; i++) {
            curr = prev2 + prev1;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};
