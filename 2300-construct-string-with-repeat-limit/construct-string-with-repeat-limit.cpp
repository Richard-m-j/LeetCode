class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26,0);
        for(char& c: s)
            freq[c-'a']++;
        priority_queue<pair<char,int>> pq;
        for(int i=0;i<26;i++)
            if(freq[i])
                pq.push({'a'+i,freq[i]});
        char prev = '\0';
        string res="";
        while(!pq.empty()){
            auto [node,f]=pq.top();
            pq.pop();
            if(node == prev){
                // cout<<"* "<<prev<<" "<<node<<endl;
                if(pq.empty())
                    break;
                auto [newNode,newF] = pq.top();
                pq.pop();
                pq.push({node,f});
                res+=newNode;
                newF--;
                if(newF)
                    pq.push({newNode,newF});
                prev = newNode;
                continue;
            }
            int l = min(repeatLimit,f);
            for(int i=0;i<l;i++)
                res += node;
            f-=l;
            if(f)
                pq.push({node,f});
            // cout<<res<<" "<<prev<<endl;
            
            prev = node;
        }
        return res;
    }
};