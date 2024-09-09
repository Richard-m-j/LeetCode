class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        unordered_set<string> visited;
        unordered_map<string,vector<string>> wordMap;
        unordered_set<string> wordSet;
        queue<string> q;
        int n = beginWord.length();
        wordList.push_back(beginWord);
        for(string& s: wordList)
            wordSet.insert(s);
        for(auto& s: wordList){
            vector<string> branches;
            for(int i=0;i<n;i++){
                string nextWord = s;
                for(int j=0;j<26;j++){
                    nextWord[i] = j + 'a';
                    if(nextWord == s)
                        continue;
                    if(wordSet.find(nextWord)!=wordSet.end()){
                        branches.push_back(nextWord);
                        cout<<s<<"-"<<nextWord<<" ";
                    }
                }
            }
            wordMap[s] = branches;
            cout<<s<<endl;
        }
        q.push(beginWord);
        int level=1;
        while(!q.empty()){
            queue<string> q1;
            while(!q.empty()){
                string curr = q.front();
                cout<<curr<<" ";
                q.pop();
                vector<string> branches = wordMap[curr];
                cout<<branches.size()<<endl;
                for(auto& next: branches){
                    cout<<next<<" ";
                    if(visited.find(next) != visited.end())
                        continue;
                    if(next == endWord)
                        return level+1;
                    q1.push(next);
                    visited.insert(next);
                }
            }
            q=q1;
            level++;
        }
        return 0;
    }
};