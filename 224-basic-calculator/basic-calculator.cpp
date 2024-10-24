class Solution {
    int operation(int a, char op, int b) {
        if (op == '+')
            return a + b;
        return a-b;
    }

public:
    int calculate(string s) {
        stack<char> charStack;
        stack<int> numStack;
        s = '(' + s + ')';
        string s1="";
        for(int i=0;i<s.length();i++){
            if(s[i] != ' ')
                s1 += s[i];
        }
        s = s1;
        for (int i = s.length() - 1; i >= 0; i--) {
            cout<<i<<" ";
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
            if(s[i+1] == '-'){
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