// Last updated: 7/24/2025, 8:33:36 AM
static const int speedUp = []{ios::sync_with_stdio(0);cin.tie(0);return 0;}();
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> tokenStack;
        for (const string& token : tokens) {
            if (isOperator(token)) {
                if (tokenStack.size() < 2)
                    return -1;
                int a = tokenStack.top(); tokenStack.pop();
                int b = tokenStack.top(); tokenStack.pop();
                tokenStack.push(applyOperator(token, b, a));
            } else {
                tokenStack.push(stoi(token));
            }
        }
        return (tokenStack.size() == 1) ? tokenStack.top() : -1;
    }

private:
    bool isOperator(const string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }

    int applyOperator(const string& op, int a, int b) {
        switch (op[0]) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
            default: return 0; 
        }
    }
};
