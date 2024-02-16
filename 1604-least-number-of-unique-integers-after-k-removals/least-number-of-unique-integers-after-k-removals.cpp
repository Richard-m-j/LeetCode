class Solution {
public:
    static bool compareSecond(const pair<int,int>& a,const pair<int,int>& b){
        return a.second < b.second;
    }
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(int &num: arr)
            mp[num]++;
        vector<pair<int,int>> mapVector(mp.begin(),mp.end());
        sort(mapVector.begin(),mapVector.end(),compareSecond);

        int count = 0, size = mapVector.size();
        for(auto & it: mapVector){
            count += it.second;
            if(count == k){
                return --size;
            }
            else if(count > k){
                return size;
            }
            size--;
        }
        return 0;
    }
};