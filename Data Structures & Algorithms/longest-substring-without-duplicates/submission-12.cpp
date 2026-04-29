class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> uset;
        int L = 0;
        int length = 0;

        for (int R = 0; R < s.size(); R++) {
            // delete until there's no duplicate in set
            // e.g. s = "abcabcbb"
            // L = 3, R = 6
            // we have to make L equals to 5 to have no duplicate
            while (uset.count(s[R]) != 0) {
                uset.erase(s[L]);
                L++;
            }
            uset.insert(s[R]);
            length = std::max(length, R - L + 1);
        }

        return length;
    }
};
