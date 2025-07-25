// Last updated: 7/24/2025, 8:31:21 AM
class Solution {
public:
    static vector<int> lexicalOrder(int n) {
        vector<int> ans(n);
        int x=1;
        for(int i=0; i<n; i++){
            ans[i]=x;
            if (x*10>n){
                if (x==n) x/=10;
                x++;
                while(x%10==0) x/=10;
            } 
            else x*=10;          
        }
        return ans;
    }
};