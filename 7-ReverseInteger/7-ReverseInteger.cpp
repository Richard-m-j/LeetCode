// Last updated: 7/24/2025, 8:36:47 AM
class Solution {
public:
    int reverse(int x) {
        int reverse = 0;
        bool sign;
        if(x<0){
            sign = false;
            if(x==INT_MIN)
                return 0;
            x = -x;
        }
        else
            sign = true;
        while(x){
            if(reverse>INT_MAX/10)
                return 0;
            reverse = reverse*10 + x%10;
            
            x/=10;
        }
        if(sign)
            return reverse;
        return -reverse;
    }
};