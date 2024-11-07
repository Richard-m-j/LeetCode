class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int bit = 1;
        int res = 1;
        while(bit){
            int len = 0;
            for(int i=0;i<candidates.size();i++){
                if(bit & candidates[i])
                    len++;
            }
            res = max(res,len);
            // cout<<bit<<" "<<len<<endl; 

            bit = bit<<1;
        }
        return res;
    }
};