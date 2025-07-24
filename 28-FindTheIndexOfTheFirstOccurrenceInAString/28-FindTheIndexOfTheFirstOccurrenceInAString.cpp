// Last updated: 7/24/2025, 8:36:11 AM
class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0;
        while(i<haystack.size()){
            if(haystack[i] == needle[0]){
                int k=0;
                for(;k<needle.size();k++)
                    if(needle[k] != haystack[i+k]) break;
                if(k==needle.size())
                    return i;
            }
            i++;
        }
        return -1;
    }
};