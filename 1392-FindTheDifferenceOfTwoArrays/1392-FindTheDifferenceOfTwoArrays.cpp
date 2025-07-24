// Last updated: 7/24/2025, 8:27:26 AM
class Solution {
public:
    bool inNums1[2001];
    bool inNums2[2001];
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector <int> list1,list2;

        for(int i: nums1)
            inNums1[1000+i]=true;
        
        for(int i: nums2)
            if(!inNums2[1000+i]&&!inNums1[1000+i])
            {
                inNums2[1000+i]=true;
                list2.push_back(i);
            }
            else if(!inNums2[1000+i])
                inNums2[1000+i]=true;

        for(int i: nums1)
            if(!inNums2[1000+i]&&inNums1[1000+i])
            {
                inNums1[1000+i]=false;
                list1.push_back(i);
            }
        
    return {list1,list2};
    }
};