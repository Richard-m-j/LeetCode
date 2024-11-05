class Solution {
public:
    int minChanges(string s) {
        int n=s.length();
        int res = 0;
        for(int i=0;i<n-1;i+=2){
            if((s[i]-'0')^(s[i+1]-'0'))
                res++;
        }
        return res;
    }
};