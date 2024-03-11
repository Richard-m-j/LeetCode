class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<order.length();i++)
            mp[order[i]] = i;
        int n = s.length();
        for(int i=0;i<n;i++)
            for(int j=0;j<n-i-1;j++)
                if(mp[s[j]] > mp[s[j+1]]){
                    char temp = s[j];
                    s[j] = s[j+1];
                    s[j+1] = temp;
                }
        return s;
    }
};