// Last updated: 7/24/2025, 8:25:51 AM
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n=gain.size();
        int curr{0},highest{0};
        for(int i=0;i<n;i++)
        {
            curr+=gain[i];
            if(curr>highest)
                highest=curr;
        }
        return highest;
    }
};