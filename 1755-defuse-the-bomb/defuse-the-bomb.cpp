class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n,0);
        if(!k)
            return res;
        if(k>0){
            for(int i=0;i<n;i++)
                for(int j=(i+1)%n;j!=(i+k+1)%n;j=(j+1)%n){
                    res[i] += code[j];}
        }
        else{
            for(int i=0;i<n;i++)
                for(int j=(i-1+n)%n;j!=(i+k-1+n)%n;j=(j-1+n)%n)
                    res[i] += code[j];
        }
        return res;
    }
};