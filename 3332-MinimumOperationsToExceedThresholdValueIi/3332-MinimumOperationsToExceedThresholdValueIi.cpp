// Last updated: 7/24/2025, 8:22:37 AM
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        map<long long,int> mp;
        for(int& num: nums)
            mp[num]++;
        int res=0;
        while(true){
            long long x,y;
            auto it = mp.begin();
            x=it->first;
            if(it->second>1)
                y=it->first;
            else
                y=(++it)->first;
            // cout<<x<<" "<<y<<endl;
            mp[x]--;
            if(!mp[x])
                mp.erase(x);
            mp[y]--;
            if(!mp[y])
                mp.erase(y);
            if(x>=k)
                break;
            long long xy = (long long)min(x,y)*(2)+max(x,y);
            mp[xy]++;
            res++;
        }
        return res;
    }
};