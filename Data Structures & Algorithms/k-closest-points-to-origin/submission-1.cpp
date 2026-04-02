class Solution {
    std::vector<std::vector<int>> heap = {{0, 0}};
    int kth;

    void siftUp(int index) {
        while (index > 1 && getVal(heap[index]) > getVal(heap[index / 2])) {
            std::swap(heap[index], heap[index / 2]);
            index /= 2;
        }
    }

    void siftDown(int index) {
        while (2 * index < heap.size()) {
            int largest = 2 * index;
            if (2 * index + 1 < heap.size() && getVal(heap[2 * index + 1]) > getVal(heap[largest])) {
                largest = 2 * index + 1;
            }

            if (getVal(heap[largest]) > getVal(heap[index])) {
                std::swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

    double getVal(std::vector<int> vec) {
        return vec[0] * vec[0] + vec[1] * vec[1];
    }

    void push(std::vector<int> point) {
        heap.emplace_back(point);
        int i = heap.size() - 1;
        siftUp(i);
        if (heap.size() > kth + 1) {
            pop();
        }
    }

    std::vector<int> pop() {
        auto res = heap[1];
        heap[1] = heap[heap.size() - 1];
        heap.pop_back();
        siftDown(1);
        return res;
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        kth = k;
        for (std::vector<int> point : points) {
            push(point);
        }
        return vector<vector<int>>(heap.begin() + 1, heap.end());
    }

};
