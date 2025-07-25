// Last updated: 7/24/2025, 8:28:58 AM
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        unordered_set <int> visited;
        queue <int> roomsFound;

        roomsFound.push(0);
        while(!roomsFound.empty())
        {
            int room = roomsFound.front();
            roomsFound.pop();
            visited.insert(room);
            for(auto key: rooms[room])
            {
                if(visited.find(key) == visited.end())
                {
                    roomsFound.push(key);
                }
            }
        }
        return rooms.size() == visited.size();
    }
};
