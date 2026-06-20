class NumMatrix {
    std::vector<std::vector<int>> prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int R = matrix.size();
        int C = matrix[0].size();

        prefix = std::vector<std::vector<int>>(R + 1, std::vector<int>(C + 1, 0));
        for (int i = 0; i < R; i++) {
            int row_prefix = 0;
            for (int j = 0; j < C; j++) {
                row_prefix += matrix[i][j];
                // matrix[i][j] == prefix[i + 1][j + 1]
                // prefix[i + 1 - 1][j + 1]
                // prefix[i][j + 1]
                int above_row = prefix[i][j + 1];
                prefix[i + 1][j + 1] = row_prefix + above_row;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++;
        col1++;
        row2++;
        col2++;

        int cur = prefix[row2][col2];
        int top = prefix[row1 - 1][col2];
        int left = prefix[row2][col1 - 1];
        int top_left = prefix[row1 - 1][col1 - 1];

        return cur - top - left + top_left;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */