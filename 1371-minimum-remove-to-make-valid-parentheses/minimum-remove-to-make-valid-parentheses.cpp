class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack <int> stack;
        string res="";
        for(int i=0;i<s.length();){
            if(s[i] == ')')
                if(stack.empty()){
                    s.erase(i,1);
                    continue;
                }
                else
                    stack.pop();
            else if(s[i]=='('){
                stack.push(i);
            }
            i++;
        }
        while(!stack.empty()){
            s.erase(stack.top(),1);
            stack.pop();
        }
        return s;
    }
};