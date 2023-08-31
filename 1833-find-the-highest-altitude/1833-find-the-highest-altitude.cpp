class Solution {
public:
    int largestAltitude(vector<int>& gain) {
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