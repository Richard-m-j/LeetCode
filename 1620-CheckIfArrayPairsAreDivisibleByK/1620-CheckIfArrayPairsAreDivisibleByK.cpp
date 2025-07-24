// Last updated: 7/24/2025, 8:26:29 AM
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        vector<int> mp(k,0);
        for(int&num: arr){
            int rem = num%k;
            if(rem < 0)
                rem += k;
            mp[rem]++;
        }
        if(mp[0]%2)
            return false;
        for(int i=1;i<=k/2;i++)
            if(mp[i] != mp[k-i])
                return false;
        return true;
    }
};