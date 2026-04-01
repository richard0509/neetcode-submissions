class Solution {
    std::vector<int> heap = {0};

    void siftUp(int index) {
        while (index > 1 && heap[index] > heap[index / 2]) {
            std::swap(heap[index], heap[index / 2]);
            index /= 2;
        }
    }

    void siftDown(int index) {
        while (2 * index < heap.size()) {
            int biggest = 2 * index;
            if (2 * index + 1 < heap.size() && heap[2 * index + 1] > heap[biggest]) {
                biggest = 2 * index + 1;
            }

            if (heap[biggest] > heap[index]) {
                std::swap(heap[biggest], heap[index]);
                index = biggest;
            } else {
                break;
            }
        }
    }

    void push(int val) {
        heap.emplace_back(val);
        int i = heap.size() - 1;
        siftUp(i);
    }

    int pop()  {
        if (heap.size() == 1) {
            return -1;
        }

        int res = heap[1];
        heap[1] = heap[heap.size() - 1];
        heap.pop_back();
        int i = 1;
        siftDown(i);
        return res;
    }
public:
    int lastStoneWeight(vector<int>& stones) {
        for (int stone : stones) {
            push(stone);
        }

        while (heap.size() > 2) {
            int big = pop();
            int small = pop();
            if (big - small) {
                push(big - small);
            }
        }
        
        if (heap.size() == 1) {
            return 0;
        }
        return heap[1];
    }
};
