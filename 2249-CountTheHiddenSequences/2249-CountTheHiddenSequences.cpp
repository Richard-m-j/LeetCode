// Last updated: 7/24/2025, 8:24:47 AM
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {

        long long low=0,high=0,val=0;
        for(int i=0;i<differences.size();i++){
            val += differences[i];
            low=min(low,val);
            high=max(high,val);
        }

        int res = (upper-high) - (lower-low)+1;
        return res>0?res:0;

    }
};