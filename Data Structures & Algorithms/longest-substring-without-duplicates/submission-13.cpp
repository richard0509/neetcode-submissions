class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> char_map;
        int L = 0;
        int length = 0;

        for (int R = 0; R < s.size(); R++) {
            // delete until there's no duplicate in set
            // e.g. s = "abcabcbb"
            // L = 3, R = 6
            // we have to make L equals to 5 to have no duplicate
            if (char_map.count(s[R]) != 0) {
                L = std::max(char_map[s[R]] + 1, L);
            }
            char_map[s[R]] = R;
            length = std::max(length, R - L + 1);
        }

        return length;
    }
};
