class Solution {
public:
    bool mp[128];
    int maxVowels(string s, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        mp['a']=true;
        mp['e']=true;
        mp['i']=true;
        mp['o']=true;
        mp['u']=true;
        int n=s.length();
        int high{0};
        for(int i=0,curr=0;i<n;i++)
            high=max(high,curr+=mp[s[i]]-(i-k>-1 && mp[s[i-k]]));

        return high;
    }
};