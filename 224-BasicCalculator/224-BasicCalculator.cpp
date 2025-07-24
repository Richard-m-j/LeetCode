// Last updated: 7/24/2025, 8:32:40 AM
class Solution {
    int operation(int a, char op, int b) {
        if (op == '+')
            return a + b;
        return a-b;
    }

public:
    int calculate(string s) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        stack<char> charStack;
        stack<int> numStack;
        s = '(' + s + ')';
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == ' ')
                continue;
            if (s[i] != '(') {
                if(s[i] == '-' || s[i] == '+' || s[i] == ')')
                    charStack.push(s[i]);
                else{
                    string num = "";
                    while(isdigit(s[i]))
                        num = s[i--] + num;
                    i++;    
                    numStack.push(stoi(num));
                }
                continue;    
            }
            int next = i+1;
            while(s[next] == ' ')
                next++;
            if(s[next] == '-'){
                charStack.pop();
                int num = -numStack.top();
                numStack.pop();
                numStack.push(num);
            }
            while(charStack.top()!=')'){
                int num1 = numStack.top();
                numStack.pop();
                if(charStack.top()!=')'){
                    char op = charStack.top();
                    charStack.pop();
                    int num2 = numStack.top();
                    numStack.pop();
                    num1 = operation(num1,op,num2);
                }
                numStack.push(num1);
            }
            charStack.pop();
        }
        return numStack.top();
    }
};