class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i{0},j{0};

        int n=s.length(),m=t.length();
        ios_base::sync_with_stdio(false);

        while(i<n)
        {
            while(j<m&&s[i]!=t[j])
                j++;
            if(j==m)
                return false;
            j++;
            i++;
        }
        return true;
        
    }
};