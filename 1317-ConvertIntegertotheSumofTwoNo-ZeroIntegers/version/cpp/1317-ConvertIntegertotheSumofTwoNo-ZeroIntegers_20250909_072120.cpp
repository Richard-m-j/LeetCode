// Last updated: 9/9/2025, 7:21:20 AM
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        auto check = [](int x){
            while(x>0){
                if(x%10==0){
                    return false;
                }
                x /= 10;
            }
            return true;
        };
        for(int i=1;i<n;i++){
            if(check(i) && check(n-i)){
                return {i,n-i};
            }
        }
        return {};
    }
};