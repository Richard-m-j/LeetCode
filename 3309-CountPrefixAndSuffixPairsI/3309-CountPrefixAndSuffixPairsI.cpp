// Last updated: 7/24/2025, 8:22:40 AM
class Solution {
private:
    bool isPrefixAndSuffix(string& a, string& b){
        int n=a.length(),m=b.length();
        if(m<n)
            return false;
        for(int i=0;i<n;i++)
            if(b[i]!=a[i] || b[m-n+i]!=a[i]){
                // cout<<a[i]<<" "<<b[m-n+i]<<endl;
                return false;
            }
        return true;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int res =0;
        // int n =words.size();
        for(int i=0;i<words.size()-1;i++)
            for(int j=i+1;j<words.size();j++){
                // cout<<i<<j<<" ";
                if(isPrefixAndSuffix(words[i],words[j])){
                    // cout<<words[i]<<" "<<words[j]<<endl;
                    res++;
                }
                // cout<<res<<endl;
            }
        return res;
    }
};