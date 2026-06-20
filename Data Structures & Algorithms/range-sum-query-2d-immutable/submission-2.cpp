class NumMatrix {
    std::vector<std::vector<int>> prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        prefix.resize(matrix.size(), std::vector<int>(matrix[0].size()));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                int up = 0;
                int left = 0;
                int left_up = 0;
                if (i == 0 && j == 0) {
                    up = 0;
                    left = 0;
                    left_up = 0;
                }
                else if (i == 0) {
                    left = prefix[i][j - 1];
                } else if (j == 0) {
                    up = prefix[i - 1][j];
                } else {
                    left = prefix[i][j - 1];
                    up = prefix[i - 1][j];
                    left_up = prefix[i - 1][j - 1];
                }
                prefix[i][j] = left + up - left_up + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int top = row1 > 0 ? prefix[row1 -1][col2] : 0;
        int left = col1 > 0 ? prefix[row2][col1 - 1] : 0;
        int top_left = (row1 > 0 && col1 > 0) ? prefix[row1 - 1][col1 - 1] : 0;
        int res = prefix[row2][col2] - top - left + top_left;
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */