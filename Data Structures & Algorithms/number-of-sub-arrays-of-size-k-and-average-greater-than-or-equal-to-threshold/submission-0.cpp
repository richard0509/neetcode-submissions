class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        std::vector<int> window;
        int L = 0;
        double sum = 0;
        int count = 0;

        for (int R = 0; R < arr.size(); R++) {
            window.push_back(arr[R]);
            sum += arr[R];
            if (window.size() == k) {
                if (sum / k >= threshold) {
                    count++;
                }
                sum -= arr[L];
                window.erase(window.begin());
                L++;
            }

        }
        return count;
    }
};