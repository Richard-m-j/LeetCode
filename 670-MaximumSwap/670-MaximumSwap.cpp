// Last updated: 7/24/2025, 8:29:50 AM
class Solution {
public:
    int maximumSwap(int num) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        string numString = to_string(num);
        int n = numString.length();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
            mp[numString[i]-'0']=i;
        
        for(int i=0;i<n;i++){
            for(int j=9;j>numString[i]-'0';j--)
                if(mp.count(j) && mp[j]>i){
                    swap(numString[i],numString[mp[j]]);
                    return stoi(numString);
                }
        }
        return num;
    }
};