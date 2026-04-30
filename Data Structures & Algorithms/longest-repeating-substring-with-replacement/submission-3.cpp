class Solution {
public:
    int characterReplacement(std::string s, int k)
    {
        int L = 0;
        int length = 0;
        int count[26] = {0};
        int max_count = 0;

        for (int R = 0; R < s.size(); R++) {
            count[s[R] - 65]++;
            max_count = std::max(count[s[R] - 65], max_count);

            while ((R - L + 1) - max_count > k) {
                count[s[L] - 65]--;
                L++;
            }
            length = std::max(R - L + 1, length);
        }
        return length;
    }
};
