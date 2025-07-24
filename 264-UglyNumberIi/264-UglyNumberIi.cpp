// Last updated: 7/24/2025, 8:32:12 AM
class Solution {
public:
    int nthUglyNumber(int n) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        vector<int>uglyList(n);
        int i1,i2,i3;
        uglyList[0] = 1;
        i1=i2=i3=0;
        for(int i=1;i<n;i++){
            int l1 = uglyList[i1]*2;
            int l2 = uglyList[i2]*3;
            int l3 = uglyList[i3]*5;

            int minElement = min(l1,min(l2,l3));
            if(minElement == l1) i1++;
            if(minElement == l2) i2++;
            if(minElement == l3) i3++;
            uglyList[i] = minElement;
        }
        return uglyList[n-1];
    }
};