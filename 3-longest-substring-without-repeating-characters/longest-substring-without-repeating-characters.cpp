class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> lastIndex(128,-1);
        int res = 0;

        int l=-1,r=0;
        while(r<s.length()){
            if(lastIndex[s[r]] >=l)
                l = lastIndex[s[r]];
            res = max(res,r-l);
            lastIndex[s[r]] = r;
    
            r++;
        }
        return res;
    }
};