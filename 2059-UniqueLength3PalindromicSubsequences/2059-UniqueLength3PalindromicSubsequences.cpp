// Last updated: 7/24/2025, 8:25:26 AM
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> firstIndex(26,-1);
        vector<int> lastIndex(26,-1);

        for(int i=0;i<s.length();i++){
            if(firstIndex[s[i]-'a']==-1)
                firstIndex[s[i]-'a'] = i;
            lastIndex[s[i]-'a'] = max(lastIndex[s[i]-'a'],i);            
        }
         
        int res=0;
        for(int i=0;i<26;i++){
            if(firstIndex[i] == -1 || lastIndex[i]==-1)
                continue;
            unordered_set<char> uniques;
            for(int j=firstIndex[i]+1;j<lastIndex[i];j++)
                if(!uniques.count(s[j]))
                    uniques.insert(s[j]);
            res += uniques.size();
        }
        return res;
    }
};