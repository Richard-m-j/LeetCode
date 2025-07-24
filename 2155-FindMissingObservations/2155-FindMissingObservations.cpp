// Last updated: 7/24/2025, 8:25:11 AM
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int m = rolls.size();
        long totSum = mean*(m+n);
        long mSum = accumulate(rolls.begin(),rolls.end(),0);
        long nSum = totSum - mSum;

        int f = (int)(nSum/n);
        if(f > 6 || f<1)
            return {};
        long rem = nSum - f*n;
        vector<int> res(n,f);

        for(int i=0;i<n;i++){
            if(!rem || res[i] == 6)
                break;

            res[i]++;
            rem--;
        }
        if(rem)
            return {};

        return res;
    }
};