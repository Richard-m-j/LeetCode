// Last updated: 7/24/2025, 8:25:23 AM
class Solution {
public:
    int minSwaps(string s) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int open=0,close=0;
        int res=0,r=s.length()-1;
        for(int i=0;i<r;i++){
            if(s[i] == ']')
                close++;
            if(s[i]=='[')
                open++;
            while(i<r && open < close){
                if(s[r] == '['){
                    // swap(s[i],s[r]);
                    res++;
                    close--;
                    open++;
                }
                r--;
            }
        }
        return res;
    }
};