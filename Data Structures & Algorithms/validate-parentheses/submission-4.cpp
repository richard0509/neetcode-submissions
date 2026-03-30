class Solution {
public:
    bool isValid(string s) {
        vector<char> s_stack;
        for(int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                s_stack.push_back(s[i]);
            }

            if (s_stack.empty()) {
                return false;
            }

            if (s[i] == ')' && s_stack.back() != '(') {
                return false;
            } else if (s[i] == ')' && s_stack.back() == '(') {
                s_stack.pop_back();
            }

            if (s[i] == '}' && s_stack.back() != '{') {
                return false;
            } else if (s[i] == '}' && s_stack.back() == '{') {
                s_stack.pop_back();
            }

            if (s[i] == ']' && s_stack.back() != '[') {
                return false;
            } else if (s[i] == ']' && s_stack.back() == '[') {
                s_stack.pop_back();
            }
        }
            return s_stack.empty();
    }
};
