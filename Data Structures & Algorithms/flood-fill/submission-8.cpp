class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int target_color = image[sr][sc];
        return helper(image, sr, sc, color, target_color);
    }

    vector<vector<int>> helper(vector<vector<int>>& image, int sr, int sc, int color, int target_color) {
        int ROW = image.size();
        int COL = image[0].size();
        
        int& pixel = image[sr][sc];

        if (std::min(sr, sc) < 0 || sr == ROW || sc == COL || pixel != target_color || pixel == color) {
            return image;            
        }

        pixel = color;

        image = helper(image, sr + 1, sc, color, target_color);
        image = helper(image, sr - 1, sc, color, target_color);
        image = helper(image, sr, sc + 1, color, target_color);
        image = helper(image, sr, sc - 1, color, target_color);

        return image;

    }

};