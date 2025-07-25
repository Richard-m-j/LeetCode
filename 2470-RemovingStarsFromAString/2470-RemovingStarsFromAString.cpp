// Last updated: 7/24/2025, 8:24:20 AM
class Solution {
public:
    string removeStars(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int n=s.length();
        int i{0},j{0};
        while(j<n)
        {
            if(s[j]=='*')
                i--;
            else
            {
                s[i]=s[j];
                i++;
            }
            j++;
        }
        return s.substr(0,i);
    }
};