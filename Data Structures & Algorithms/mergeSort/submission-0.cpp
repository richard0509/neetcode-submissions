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
    vector<Pair> mergeSort(vector<Pair>& pairs) {
        if (pairs.size() <= 1) {
            return pairs;
        }
        int n = pairs.size();
        int half = n / 2;
        std::vector<Pair> left = std::vector<Pair>(pairs.begin(), pairs.begin() + half);
        std::vector<Pair> right = std::vector<Pair>(pairs.begin() + half, pairs.end());
        std::vector<Pair> arr1 = mergeSort(left);
        std::vector<Pair> arr2 = mergeSort(right);

        int i = 0;
        int j = 0;
        std::vector<Pair> new_vec;
        while (i < arr1.size() && j < arr2.size()) {
            if (arr1[i].key <= arr2[j].key) {
                new_vec.push_back(arr1[i]);
                i++;
            } else {
                new_vec.push_back(arr2[j]);
                j++;
            }
        }
        if (i == arr1.size()) {
            new_vec.insert(new_vec.end(), arr2.begin() + j, arr2.end());
        } else {
            new_vec.insert(new_vec.end(), arr1.begin() + i, arr1.end());
        }
        return new_vec;
        
    }
};
