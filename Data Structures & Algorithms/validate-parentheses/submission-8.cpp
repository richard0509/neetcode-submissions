class Solution {
public:
    bool isValid(string s) {
        vector<char> s_stack;
        for(int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                s_stack.emplace_back(s[i]);
            } else {
                if (s_stack.empty()) {
                    return false;
                } else {
                    if ((s[i] == ')' && s_stack.back() == '(') || (s[i] == '}' && s_stack.back() == '{') || (s[i] == ']' && s_stack.back() == '[')) {
                        s_stack.pop_back();
                    } else {
                        return false;
                    }
                }
    
            }

        }
            return s_stack.empty();
    }
};
