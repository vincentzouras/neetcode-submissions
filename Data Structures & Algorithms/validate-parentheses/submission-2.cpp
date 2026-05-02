class Solution {
public:
    bool isValid(string s) {
        vector<char> char_stack; 
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                char_stack.push_back(c);
            } else {
                if (char_stack.empty()) return false;

                char top = char_stack.back();
                char_stack.pop_back();

                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') || 
                    (c == '}' && top != '{'))
                    return false;
            }
        }
        return char_stack.empty();
    }
};
