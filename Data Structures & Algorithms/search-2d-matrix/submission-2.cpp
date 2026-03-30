class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        int r = row * col - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (matrix[mid / col][mid % col] > target) {
                r = mid - 1;
            } else if (matrix[mid / col][mid % col] < target) {
                l = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
