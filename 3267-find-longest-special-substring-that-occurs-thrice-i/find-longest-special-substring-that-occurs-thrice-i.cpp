class Solution {
public:
    int maximumLength(string s) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        unordered_map<string,int> mp;
        int n = s.length();
        for(int i=0;i<n;i++){
            string special="";
            special+=s[i];
            mp[special]++;
            for(int j=i+1;j<n;j++){
                if(s[j]!=special[0])
                    break;
                special += s[j];
                mp[special]++;
            }
        }
        int res = -1;
        for(auto& it: mp){
            // cout<<it.first<<" "<< it.second<<endl;
            int len = (it.first).length();
            if(it.second>2){
                res = max(res,len);
            }
        }
        return res;
    }
};