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
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        std::vector<std::vector<Pair>> ans;
        if (pairs.empty()) {
            return ans;
        }
        ans.push_back(pairs);
        for (int i = 1, k = 0; i < pairs.size(); i++, k++) {
            int j = i - 1;
            while (j >= 0 && pairs[j].key > pairs[j + 1].key) {
                Pair temp = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = temp;
                j--;
            }
            ans.push_back(pairs);
        }
        return ans;
    }
};
