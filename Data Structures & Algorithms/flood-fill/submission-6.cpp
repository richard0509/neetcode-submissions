class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int old_color = image[sr][sc];
        return helper(image, sr, sc, color, old_color);
    }

    vector<vector<int>> helper(vector<vector<int>>& image, int sr, int sc, int color, int old_color) {
        int ROW = image.size();
        int COL = image[0].size();
        

        if (std::min(sr, sc) < 0 || sr == ROW || sc == COL || image[sr][sc] != old_color || image[sr][sc] == color) {
            return image;            
        }

        image[sr][sc] = color;

        image = helper(image, sr + 1, sc, color, old_color);
        image = helper(image, sr - 1, sc, color, old_color);
        image = helper(image, sr, sc + 1, color, old_color);
        image = helper(image, sr, sc - 1, color, old_color);

        return image;

    }

};