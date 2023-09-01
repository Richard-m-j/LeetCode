class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        vector <int> list1,list2;
        sort(nums1.begin(), nums1.end());
        nums1.erase(unique(nums1.begin(), nums1.end()), nums1.end());

        sort(nums2.begin(), nums2.end());
        nums2.erase(unique(nums2.begin(), nums2.end()), nums2.end());

        set_difference(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),back_inserter(list1));
        set_difference(nums2.begin(),nums2.end(),nums1.begin(),nums1.end(),back_inserter(list2));
    return {list1,list2};
    }
};