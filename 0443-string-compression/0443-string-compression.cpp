class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int count=1;
        int i=0,j;
        int index=0;
        while(i<n)
        {
            j=i+1;
            while(j<n&&chars[i]==chars[j]&&j<n)
                j++;
            chars[index++]=chars[i];
            count=j-i;
            if(count>1)
            {
                string num=to_string(count);
                for(int k=0;k<num.length();k++)
                    chars[index++]=num[k];
            }
            i=j;
        }
        return index;
        // for(int i=1;i<n;i++)
        // {
        //     if(chars[i]!=current)
        //     {
        //         chars[j++]=current;
        //         if(count>1)
        //         {
        //             string num=to_string(count);
        //             for(int k=0;k<num.length();k++)
        //                 chars[j++]=num[k];
        //         }
        //         current=chars[i];
        //         count=1;
        //     }
        //     else
        //         count++;
        // }
        // chars[j++]=current;
        // if(count>1)
        // {
        //     string num=to_string(count);
        //     for(int k=0;k<num.length();k++)
        //         chars[j++]=num[k];
        // }
    }
};