// Last updated: 7/24/2025, 8:31:46 AM
class Solution {
private:
    int countOnes(int n){
        int res=0;
        while(n){
            if(n&1)
                res++;
            n=n>>1;
        }
        return res;
    }
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1,0);
        for(int i=0;i<=n;i++)
            res[i] = countOnes(i);
        return res;
    }
};