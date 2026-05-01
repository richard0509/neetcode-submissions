class Solution {
public:
    int maxTurbulenceSize(std::vector<int>& arr)
    {
        int L = 0;
        int res = 1;

        for (int R = 1; R < arr.size(); R++) {
            if (arr[R] == arr[R - 1]) {
                L = R;
            }
            else if ((arr[R - 2] - arr[R - 1] > 0) ==
                     (arr[R - 1] - arr[R]) > 0) {
                L = R - 1;
            }
            res = std::max(R - L + 1, res);
        }

        return res;
    }
};