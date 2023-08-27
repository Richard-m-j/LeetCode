class Solution {
public:
    string reverseWords(string s) {
        stack <string> stack;
        string word="";
        int length=s.length();
        for(int i=0;i<length;i++)
        {
            if(s[i]==' '&&word.length()!=0)
            {
                stack.push(word);
                word="";
            }
            else if(s[i]!=' ')
                word+=s[i];
        }
        if(word.length()!=0)
            stack.push(word);
        string out="";
        int size=stack.size()-1;
        for(int i=0;i<size;i++)
        {
            out+=stack.top();
            stack.pop();
            out+=" ";
        }
        out+=stack.top();
        return out;
    }
};