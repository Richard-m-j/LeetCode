class Solution {
public:
    int climbStairs(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if(n<=0)
            return 0;
        if(n==1)
            return 1;
        int a{1},b{1};

        for(int i=1;i<n;i++)
        {
            int temp = a;
            a = b;
            b = temp + b;
        }
        return b;
    }
};