/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    vector<pair<int,int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> mat(m,vector<int>(n,-1));
        ListNode*ptr = head;
        int dir = 0;
        int x=0,y=0;        
        while(ptr){
            mat[x][y] = ptr->val;
            // cout<<x<<","<<y<<endl;
            ptr = ptr->next;
            int nextX = x + dirs[dir].first;
            int nextY = y + dirs[dir].second;
            if(nextX>=0 && nextY>=0 && nextX<m && nextY<n && mat[nextX][nextY] == -1){
                cout<<endl;
                x = nextX;
                y = nextY;
            }
            else{
                dir = (dir+1)%4;
                x += dirs[dir].first;
                y += dirs[dir].second;
            }
        }
        return mat;
    }
};