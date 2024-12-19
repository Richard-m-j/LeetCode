class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res=0;
        int l=0,r=0,n=arr.size();
        for(int i=0;i<n;i++){
            r=max(arr[i],r);
            if(r==i)
                res++;
        }
        return res;
    }
};