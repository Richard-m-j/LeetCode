// Last updated: 7/24/2025, 8:30:27 AM
int speedUp=[]{
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class Solution {
private: 

    int timeDifference(string a, string b){
        int m1 = stoi(a.substr(3,2));
        int m2 = stoi(b.substr(3,2));
        int h1 = stoi(a.substr(0,2));
        int h2 = stoi(b.substr(0,2));
        int diff = (m1-m2 + (h1-h2)*60);
        return min(diff,1440-diff);
    }
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        sort(timePoints.begin(),timePoints.end(),[](auto& a, auto&b){
            if(a[0]!=b[0])
                return a[0]<b[0];
            if(a[1]!=b[1])
                return a[1]<b[1];
            if(a[3]!=b[3])
                return a[3]<b[3];    
            return a[4]<b[4];
        });
        // timePoints.push_back(timePoints[0]);
        int minDifference=INT_MAX;
        for(int i=1;i<n;i++){
            int diff = timeDifference(timePoints[i],timePoints[i-1]);
            minDifference = min(minDifference,diff);
        }
        minDifference = min(minDifference,timeDifference(timePoints[n-1],timePoints[0]));
        return minDifference;
    }
};