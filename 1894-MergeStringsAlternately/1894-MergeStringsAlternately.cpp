// Last updated: 7/24/2025, 8:25:47 AM
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merged="";
        int i=0,j=0;
        for(;i<word1.length()&&j<word2.length();i++,j++)
            merged+=word1[i],merged+=word2[j];
        
        for(;i<word1.length();i++)
            merged+=word1[i];

        for(;j<word2.length();j++)
            merged+=word2[j];

        return merged;
    }
};