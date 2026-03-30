class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (std::vector<int> arr : matrix) {
            int l = 0;
            int r = arr.size() - 1;

            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (arr[mid] > target) {
                    r = mid - 1;
                } else if (arr[mid] < target) {
                    l = mid + 1;
                } else {
                    return true;
                }
            }
        }
        return false;
    }
};
