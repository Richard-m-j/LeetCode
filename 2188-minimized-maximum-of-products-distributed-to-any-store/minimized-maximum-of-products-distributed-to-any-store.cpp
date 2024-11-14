class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        // sort(quantities.begin(),quantities.end());
        int l=1,r=*max_element(quantities.begin(),quantities.end());
        while(l<=r){
            int m = l + (r-l)/2;
            int numDistributions = 0;
            for(int i=0;i<quantities.size();i++){
                numDistributions += ceil(quantities[i]/float(m));
            }
            // cout<<m<<" "<<numDistributions<<endl;
            // if(numDistributions==n)
            //     return m;
            if(numDistributions<=n)
                r=m-1;
            else
                l=m+1;
        }
        return l;
    }
};