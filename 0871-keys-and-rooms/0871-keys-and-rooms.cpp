class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        ios_base::sync_with_stdio(false);
        
        vector<vector<int>> roomsFound;
        roomsFound.push_back(rooms[0]);
        vector<bool> keysFound(rooms.size(), false);
        keysFound[0] = true;

        while (!roomsFound.empty()) {
            vector<int> room = roomsFound[0];
            roomsFound.erase(roomsFound.begin()); // Remove the first room from the list

            for (auto key : room) {
                if (!keysFound[key]) {
                    roomsFound.push_back(rooms[key]);
                    keysFound[key] = true;
                }
            }
        }

        for (bool i : keysFound) {
            if (!i) {
                return false;
            }
        }

        return true;
    }
};
