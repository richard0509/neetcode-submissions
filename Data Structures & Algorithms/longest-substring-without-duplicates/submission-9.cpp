class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> uset;
        int L = 0;
        int length = -1;

        for (int R = 0; R < s.size(); R++) {
            while (uset.count(s[R]) != 0) {
                uset.erase(s[L]);
                L++;
            }
            uset.insert(s[R]);
            length = std::max(length, R - L + 1);
        }

        if (length == -1) {
            return uset.size();
        }
        return length;
    }
};
