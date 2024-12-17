class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26,0);
        for(char& c: s)
            freq[c-'a']++;
        string res="";
        int i=25,prev=-1;
        while(true){
            int idx=-1;
            for(i=25;i>=0;i--)
                if(freq[i]){
                    idx = i;
                    break;
                }
            if(idx == -1)
                break;
            if(idx==prev){
                // cout<<res<<" "<<idx<<" ";
                for(i=idx-1;i>=0;i--)
                    if(freq[i]){
                        idx = i;
                        break;
                    }
                if(i == -1){
                    cout<<idx<<" ";
                    break;}
                char node = char('a'+idx);
                res += node;
                freq[idx]--;
                prev = idx;
                continue;
            }
            int l = min(repeatLimit,freq[idx]);
            char node = char('a'+idx);
            freq[idx] -= l;
            for(int j=0;j<l;j++)
                res+=node;
            prev = idx;
        }
        return res;
    }
};