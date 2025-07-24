// Last updated: 7/24/2025, 8:22:31 AM
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int subNumber=0;
        int n = nums.size();
        vector<int> subNum(n,0);
        int prevParity = nums[0]%2;
        for(int i=1;i<n;i++){
            if(nums[i]%2 == prevParity){
                subNumber++;
            }
            subNum[i]=subNumber;
            prevParity = nums[i]%2;
        }
        vector<bool> res;
        for(vector<int>& q: queries){
            res.push_back(subNum[q[0]]==subNum[q[1]]);
        }
        return res;
    }
};