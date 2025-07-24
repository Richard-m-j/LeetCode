// Last updated: 7/24/2025, 8:34:04 AM
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(),wordList.end());
        if(wordSet.find(endWord) == wordSet.end()){
            return 0;
        }
        if(wordSet.count(beginWord)){
            wordSet.erase(beginWord);
        }
        wordSet.insert(beginWord);
        queue<string> q;
        int level = 1;
        q.push(beginWord);
        while(!q.empty()){
            int len = q.size();
            for(int i=0;i<len;i++){
                string node = q.front();
                q.pop();

                if(node==endWord){
                    return level;
                }
                for(int j=0;j<node.length();j++){
                    char originalChar = node[j];
                    for(node[j] ='a';node[j]<='z';node[j]++){
                        if(node[j]==originalChar){
                            continue;
                        }

                        if(wordSet.count(node)){
                            wordSet.erase(node);
                            q.push(node);
                        }
                    }
                    node[j]=originalChar;
                }
            }
            level++;
        }
        return 0;
    }
};