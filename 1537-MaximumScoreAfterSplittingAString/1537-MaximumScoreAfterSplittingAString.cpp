// Last updated: 7/24/2025, 8:26:46 AM
class Solution {
public:
    int maxScore(string s) {
        int numOnes =0;
        for(char &c: s)
            if(c=='1')
                numOnes++;
        int res=0,numZeros=0;

        for(int i=0;i<s.length()-1;i++){
            if(s[i]=='0')
                numZeros++;
            else 
                numOnes--;
            res = max(res,numOnes+numZeros);
        }
        return res;
    }
};