// Last updated: 7/24/2025, 8:35:12 AM
class Solution {
public:
    int climbStairs(int n) {
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        int prev1=2,prev2=1;
        for(int i=3;i<=n;i++){
            int ways = prev1 + prev2;
            prev2 = prev1;
            prev1 = ways;
        }
        return prev1;
    }
};