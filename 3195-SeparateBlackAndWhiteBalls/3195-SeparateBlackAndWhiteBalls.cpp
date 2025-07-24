// Last updated: 7/24/2025, 8:22:51 AM
class Solution {
public:
    long long minimumSteps(string s) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int r=s.length()-1;
        long long res = 0;
        while(r>=0 && s[r]=='1')
            r--;
        for(int i=r;i>=0;i--){
            if(s[i]=='1'){
                res += r-i;
                r--;
            }
        }
        return res;
    }
};