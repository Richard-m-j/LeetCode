class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int bit = 1;
        int res = 1;
        while(bit<=10e6){
            int len = 0;
            for(int i=0;i<candidates.size();i++)
                if(bit & candidates[i])
                    len++;
            
            res = max(res,len);

            bit = bit<<1;
        }
        return res;
    }
};