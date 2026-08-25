class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> s; 

        for (string token : tokens) {
            if (string("+-*/").find(token) == string::npos) {
                // num
                s.push(stoi(token));
            } else {
                // operation
                int num2 = s.top();
                s.pop();
                int num1 = s.top();
                s.pop();

                if (token == "+") {
                    s.push(num1 + num2);
                } else if (token == "-") {
                    s.push(num1 - num2);
                } else if (token == "/") {
                    s.push(num1 / num2);
                } else { // *
                    s.push(num1 * num2);
                }
            }
        }

        return s.top();
    }
};
