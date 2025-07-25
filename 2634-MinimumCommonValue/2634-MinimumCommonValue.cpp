// Last updated: 7/24/2025, 8:23:42 AM
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        // if(nums1[nums1.size() -1] < nums2[0] || nums2[nums2.size() -1] < nums1[0])
        //     return -1;
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] == nums2[j])
                return nums1[i];
            else if(nums1[i] < nums2[j])
                i++;
            else
                j++;
        }
        return -1;
    }
};