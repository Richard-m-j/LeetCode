// Last updated: 7/24/2025, 8:24:07 AM
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> arr(pref.size());
        arr[0] = pref[0];
        for(int i=1;i<pref.size();i++){
            arr[i] = pref[i-1] ^ pref[i];
        }
        return arr;
    }
};