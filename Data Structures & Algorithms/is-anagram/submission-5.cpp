class Solution {
public:
    bool isAnagram(string s, string t) {

        std::unordered_map<char, int> maps;
        for (char c : s) {
            maps[c]++;
        }

        for (char c : t) {
            maps[c]--;
        }

        for (auto& pair : maps) {
            if (pair.second != 0) {
                return false;
            }
        }


        return true;
    }
};
