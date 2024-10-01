class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
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