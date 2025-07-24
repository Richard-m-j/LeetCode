// Last updated: 7/24/2025, 8:27:36 AM
class Solution {
public:
    unordered_map <int,int> mp;
    bool freq[2001];
    bool uniqueOccurrences(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<n;i++)
            mp[arr[i]]++;
        
        int m=mp.size();
        for(auto& i: mp)
            if(!freq[1000+i.second])
                freq[1000+i.second]=true;
            else
                return false;
        return true;
    }
};