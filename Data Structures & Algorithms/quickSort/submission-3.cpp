// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<Pair> quickSort(vector<Pair>& pairs) {
        quickSortHelper(pairs, 0, pairs.size() - 1);
        return pairs;
    }

    void quickSortHelper(std::vector<Pair>& pairs, int s, int e) {
        if (e - s <= 0) {
            return;
        }

        int left = s;
        auto pivot = pairs[e];
        for (int i = s; i < e; i++) {
            if (pairs[i].key < pivot.key) {
                auto temp = pairs[left];
                pairs[left] = pairs[i];
                pairs[i] = temp;
                left++;
            }
        }
        pairs[e] = pairs[left];
        pairs[left] = pivot;

        quickSortHelper(pairs, s, left - 1);
        quickSortHelper(pairs, left + 1, e);

        
    }
};
