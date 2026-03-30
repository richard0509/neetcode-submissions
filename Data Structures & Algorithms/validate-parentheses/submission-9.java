class Solution {
    public boolean isValid(String s) {
        ArrayList<Character> st = new ArrayList<>();
        for (char c : s.toCharArray()) {
            if (c == '(' || c == '{' || c == '[') {
                st.add(c);
            } else {
                if (st.isEmpty()) {
                    return false;
                } else {
                    if ((c == ')' && st.get(st.size() - 1) == '(') || (c == '}' && st.get(st.size() - 1) == '{') || (c == ']' && st.get(st.size() - 1) == '[')) {
                        st.remove(st.size() - 1);
                    } else {
                        return false;
                    }
                }
            }
        }
        return st.isEmpty();
    }
}
