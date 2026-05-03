class Solution {
public:
    bool isPalindrome(std::string s)
    {
        int L = 0;
        int R = s.size() - 1;

        while (L < R) {
            if (!isalnum(s[L])) {
                L++;
                continue;
            }
            if (!isalnum(s[R])) {
                R--;
                continue;
            }
            if (std::tolower(s[L]) != std::tolower(s[R])) {
                return false;
            }
            L++;
            R--;
        }
        return true;
    }
};