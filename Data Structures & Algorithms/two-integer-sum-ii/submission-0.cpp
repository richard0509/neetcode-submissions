class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target)
    {
        int L = 0;
        int R = numbers.size() - 1;

        std::vector<int> res;

        while (L < R) {
            if (numbers[L] + numbers[R] > target) {
                R--;
            }
            else if (numbers[L] + numbers[R] < target) {
                L++;
            }
            else {
                res.emplace_back(L + 1);
                res.emplace_back(R + 1);
                break;
            }
        }

        return res;
    }
};
