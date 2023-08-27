class Solution {
public:
    string reverseWords(string s) {
        int left=s.length()-1;
        int right=s.length();
        string out="";
        while(left>=0)
        {
            if(s[left]==' '&&(left+1)==right)
            {
                left--;
                right--;
                continue;
            }
            if(s[left]==' ')
            {
                for(int i=left+1;i<right;i++)
                    out+=s[i];
                if(left!=0)
                    out+=" ";
                right=left;
            }
            left--;
        }
        if((left+1)!=right)
            for(int i=left+1;i<right;i++)
                out+=s[i];
        if(out[out.length()-1]==' ')
            out = out.substr(0, out.size() - 1);
        return out;
    }
};