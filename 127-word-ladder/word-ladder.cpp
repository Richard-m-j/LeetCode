class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        unordered_set<string> visited;
        unordered_set<string> words(wordList.begin(),wordList.end());
        queue<string> q;
        // for(string& s: wordList)
        //     words.insert(s);
        int n = beginWord.length();
        q.push(beginWord);
        int level=1;
        while(!q.empty()){
            queue<string> q1;
            while(!q.empty()){
                string curr = q.front();
                // cout<<curr<<" ";
                q.pop();
                for(int i=0;i<n;i++){
                    char originalChar = curr[i];
                    for(int j=0;j<26;j++){
                        curr[i] = j+'a';
                        if(curr[i] == originalChar)
                            continue;
                        if(words.find(curr)!=words.end() && visited.find(curr)==visited.end())
                            if(curr == endWord)
                                return level+1;
                            else{
                                q1.push(curr);
                                visited.insert(curr);
                            }
                    }
                    curr[i] = originalChar;
                }
            }
            q=q1;
            level++;
        }
        return 0;
    }
};