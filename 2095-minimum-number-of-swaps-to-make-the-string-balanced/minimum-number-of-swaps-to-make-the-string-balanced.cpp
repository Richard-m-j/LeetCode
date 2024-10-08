class Solution {
public:
    int minSwaps(string s) {
        int open=0,close=0;
        int res=0,r=s.length()-1;
        for(int i=0;i<s.length();i++){
            if(s[i] == ']')
                close++;
            if(s[i]=='[')
                open++;
            while(i<r && open < close){
                if(s[r] == '['){
                    swap(s[i],s[r]);
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