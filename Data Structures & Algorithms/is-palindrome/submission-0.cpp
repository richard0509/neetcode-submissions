class Solution {
public:
    bool isPalindrome(std::string s)
    {
        for (int i = 0; i < s.size(); i++) {
            s[i] = tolower(s[i]);
        }
        int L = 0;
        int R = s.size() - 1;

        while (L < R) {
            if (!isdigit(s[L]) && !isalpha(s[L])) {
                L++;
                continue;
            }
            if (!isdigit(s[R]) && !isalpha(s[R])) {
                R--;
                continue;
            }
            if (s[L] != s[R]) {
                return false;
            }
            L++;
            R--;
        }
        return true;
    }
};