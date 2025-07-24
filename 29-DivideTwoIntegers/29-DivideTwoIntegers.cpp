// Last updated: 7/24/2025, 8:36:09 AM
class Solution {
public:
     int divide(int a, int b) {
    if(a==INT_MIN && b==-1)return INT_MAX;
    if(a==INT_MIN && b==1)return INT_MIN;
        int ans=0;
        long long dd=abs(a);
        long long dv=abs(b);
        while(dv<=dd){
            long long sum=dv,count=1;
            while(sum<=dd-sum){
                sum+=sum;
                count+=count;
            }
            ans+=count;
            dd-=sum;
        }
        if((a<0&&b>0)||a>0&&b<0){return -ans;}
        return ans;
        
    }
};