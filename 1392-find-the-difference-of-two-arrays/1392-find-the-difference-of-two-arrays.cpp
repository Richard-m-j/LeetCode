class Solution {
public:
    bool inNums1[2001];
    bool inNums2[2001];

    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        vector<int> list1, list2;

        for (int i : nums1) {
            int index = 1000 + i;
            inNums1[index] = true;
        }

        for (int i : nums2) {
            int index = 1000 + i;
            if (!inNums2[index] && !inNums1[index]) {
                inNums2[index] = true;
                list2.push_back(i);
            } else if (!inNums2[index]) {
                inNums2[index] = true;
            }
        }

        for (int i : nums1) {
            int index = 1000 + i;
            if (!inNums2[index] && inNums1[index]) {
                inNums1[index] = false;
                list1.push_back(i);
            }
        }

        return {list1, list2};
    }
};
