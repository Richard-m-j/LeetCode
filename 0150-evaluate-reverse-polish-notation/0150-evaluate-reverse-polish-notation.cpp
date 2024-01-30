static const int speedUp = []{ios::sync_with_stdio(0);cin.tie(0);return 0;}();
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> tokenStack;
        int i = 1;
        tokenStack.push(stoi(tokens[0]));
        for(int i =1;i<tokens.size(); i++)
        {
            string current = tokens[i];
            if(current == "+" || current == "-" || current == "*" || current == "/")
            {
                if(tokenStack.size() < 2)
                    return -1;
                int a = tokenStack.top();
                tokenStack.pop();
                int b = tokenStack.top();
                tokenStack.pop();
                if(current == "+")
                    tokenStack.push(a+b);
                else if(current == "-")
                    tokenStack.push(b-a);
                else if(current == "*")
                    tokenStack.push(a*b);
                else 
                    tokenStack.push(b/a);
            }
            else
                tokenStack.push(stoi(current));
        }
        if(tokenStack.size() == 1)
            return tokenStack.top();
        return -1;
    }
};