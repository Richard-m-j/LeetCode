// Last updated: 7/24/2025, 8:28:36 AM
class Solution {
public:
    int minAddToMakeValid(string s) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int res = 0,lb=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
                lb++;
            else
               lb--;
            
            if(lb<0){
                res++;
                lb=0;
            }
            // cout<<res<<" ";
        }

        return res + lb;
    }
};