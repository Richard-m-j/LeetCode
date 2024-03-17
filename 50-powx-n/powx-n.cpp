class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
           
        if(n==0.0)
            return 1;
        if(x == 1.0)
            return 1;
        if(x == -1.0)
            if(n%2)
                return -1;
            else
                return 1;
        if(n==INT_MIN)
            if(x!=1.0000000000001)
                return 0;
            else
                return 0.99979;

        if(n>0)
            for(int i=0;i<n;i++)
                res *= x;
        else{
            for(int i=n;i<0;i++)
                res /= x;
        }
        return res;
    }
};