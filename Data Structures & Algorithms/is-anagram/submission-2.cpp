class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        std::unordered_map<char, int> maps;
        for (char c : s) {
            maps[c]++;
        }

        for (char c : t) {
            maps[c]--;
        }

        for (char c : t) {
            if (maps[c] != 0) {
                return false;
            }
        }

        return true;
    }
};
