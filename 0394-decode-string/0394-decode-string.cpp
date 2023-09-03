class Solution {
public:
    string decodeString(string s) {
        string decoded="";
        int n=s.length();
        int i{0};

        vector <string> stack;

        for(char c: s)
        {
            if(c!=']')
            {
                string str="";
                str+=c;
                stack.push_back(str);
            }
            else
            {
                string code="";
                while(!stack.empty()&&stack.back()!="[")
                {
                    code=stack.back()+code;
                    stack.pop_back();
                }

                stack.pop_back();

                string numStr = "";
                while (!stack.empty() && isdigit(stack.back()[0])) 
                {
                    numStr = stack.back() + numStr; 
                    stack.pop_back();
                }
                int num = stoi(numStr);

                string next="";
                while(num>0)
                {
                    next+=code;
                    num--;
                }
                stack.push_back(next);
            }
        }
        for(string item: stack)
            decoded+=item;
        return decoded;
    }
};