// Last updated: 7/24/2025, 8:28:52 AM
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());
        int res = r;
        while(l<=r){
            int m = l+(r-l)/2;
            long hours = 0;
            for(int i=0;i<piles.size();i++)
                hours+=ceil(piles[i]/(double)m);
            if(hours>h)
                l=m+1;
            else{
                res = min(m,res);
                r=m-1;
            }
            cout<<m<<" "<<hours<<" "<<l<<" "<<r<<" "<<endl;
        }
        return res;
    }
};