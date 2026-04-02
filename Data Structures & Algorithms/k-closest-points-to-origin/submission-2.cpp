class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::vector<std::vector<int>> ans(k);

        std::priority_queue<std::vector<int>> heap;

        for (std::vector<int> point : points) {
            int x = point[0];
            int y = point[1];
            heap.push({x * x + y * y, x, y});
            if (heap.size() > k) {
                heap.pop();
            }
        }

        for (int i = 0; i < k; i++) {
            int x = heap.top()[1];
            int y = heap.top()[2];
            heap.pop();
            ans[i] = {x, y};
        }

        return ans;
    }

};
