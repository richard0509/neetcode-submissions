class Solution {
public:
    int getSum(int a, int b) {
        int sum = a ^ b;
        int carry = a & b;
        return sum + 2 * carry;
    }
};
