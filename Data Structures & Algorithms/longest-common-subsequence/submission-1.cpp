class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j = 0;

        int m = text1.size();
        int n = text2.size();
        std::vector<std::vector<int>> memo(m, std::vector<int>(n, -1));
        return dp(text1, text2, i, j, memo);
    }

    int dp(std::string& text1, std::string& text2, int i, int j, std::vector<std::vector<int>>& memo) {
        int count = 0;
        if (i >= text1.size() || j >= text2.size()) {
            return count;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        if (text1[i] == text2[j]) {
            count = 1 + dp(text1, text2, i + 1, j + 1, memo);
        } else {
            count = std::max(dp(text1, text2, i + 1, j, memo), dp(text1, text2, i, j + 1, memo));
        }

        memo[i][j] = count;
        return memo[i][j];
    }
};
