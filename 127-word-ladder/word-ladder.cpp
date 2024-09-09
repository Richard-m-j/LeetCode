class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        unordered_set<string> visited;
        unordered_set<string> words;
        queue<string> q;
        for(string& s: wordList)
            words.insert(s);
        int n = beginWord.length();
        q.push(beginWord);
        int level=1;
        while(!q.empty()){
            queue<string> q1;
            while(!q.empty()){
                string curr = q.front();
                cout<<curr<<" ";
                q.pop();
                for(int i=0;i<n;i++){
                    string next = curr;
                    for(int j=0;j<26;j++){
                        next[i] = j+'a';
                        if(words.find(next)!=words.end() && visited.find(next)==visited.end())
                            if(next == endWord)
                                return level+1;
                            else{
                                q1.push(next);
                                visited.insert(next);
                            }
                    }
                }
            }
            q=q1;
            level++;
        }
        return 0;
    }
};