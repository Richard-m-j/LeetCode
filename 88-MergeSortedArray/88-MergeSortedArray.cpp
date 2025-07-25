// Last updated: 7/24/2025, 8:34:50 AM
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int i = m-1, j = n-1;
        int k = m+n-1;

        while(i>=0 && j>=0)
            if(nums1[i] > nums2[j])
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        while(j>=0)
            nums1[k--] = nums2[j--];
           
    }
};