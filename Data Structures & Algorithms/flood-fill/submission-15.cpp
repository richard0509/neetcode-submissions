class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int target_color = image[sr][sc];
        helper(image, sr, sc, color, target_color);
        return image;
    }

    void helper(vector<vector<int>>& image, int sr, int sc, int color, int target_color) {
        int ROW = image.size();
        int COL = image[0].size();

        // out of bounds &&
        // is not target color
        // already is the color we want to fill
        if (std::min(sr, sc) < 0 || sr == ROW || sc == COL || image[sr][sc] != target_color || image[sr][sc] == color) {
            return;            
        }

        // modify image[sr][sc]
        image[sr][sc] = color;

        // perform for adjacent image[sr][sc]s
        // up, down, right, left
        helper(image, sr + 1, sc, color, target_color);
        helper(image, sr - 1, sc, color, target_color);
        helper(image, sr, sc + 1, color, target_color);
        helper(image, sr, sc - 1, color, target_color);

        return;

    }

};