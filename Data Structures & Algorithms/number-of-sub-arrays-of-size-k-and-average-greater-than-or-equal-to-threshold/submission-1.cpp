class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        std::vector<int> window;
        int L = 0;
        double sum = 0;
        int count = 0;

        for (int R = 0; R < arr.size(); R++) {
            sum += arr[R];
            if (R - L >= k - 1) {
                if (sum / k >= threshold) {
                    count++;
                }
                sum -= arr[L];
                L++;
            }

        }
        return count;
    }
};