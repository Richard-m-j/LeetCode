class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        char current=chars[0];
        int count=1;
        int j=0;
        for(int i=1;i<n;i++)
        {
            if(chars[i]!=current)
            {
                chars[j++]=current;
                if(count>1)
                {
                    string num=to_string(count);
                    for(int k=0;k<num.length();k++)
                        chars[j++]=num[k];
                }
                current=chars[i];
                count=1;
            }
            else
                count++;
        }
        chars[j++]=current;
        if(count>1)
        {
            string num=to_string(count);
            for(int k=0;k<num.length();k++)
                chars[j++]=num[k];
        }
        return j;
    }
};