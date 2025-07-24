// Last updated: 7/24/2025, 8:27:34 AM
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        unordered_set<string> folderSet;
        sort(folder.begin(),folder.end());
        for(string& s:folder){
            string curr = "";
            bool isSubFolder = false;
            int i=0;
            while(i<s.length()){
                curr += s[i++];
                while(i<s.length() && s[i]!='/')
                    curr += s[i++];
                if(folderSet.count(curr)){
                    isSubFolder = true;
                    break;
                } 
            }
            if(!isSubFolder)
                folderSet.insert(s);
        }
        vector<string> res(folderSet.begin(),folderSet.end());
        return res;
    }
};