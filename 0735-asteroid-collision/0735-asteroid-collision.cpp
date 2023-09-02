#include <vector>

class Solution {
public:
    std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        std::vector<int> stack;

        for (int asteroid : asteroids) {
            bool collisionHandled = false;
            
            while (!stack.empty() && stack.back() > 0 && asteroid < 0) {
                int top = stack.back();
                stack.pop_back();
                
                if (-asteroid > top) {
            // Current asteroid survives, continue checking with the next stack element.
                    continue;
                } else if (-asteroid == top) {
                    // Both asteroids annihilate each other.
                    collisionHandled = true;
                    break;
                } 
                else {
                    // Top asteroid survives, push it back, and continue checking.
                    stack.push_back(top);
                    collisionHandled = true;
                    break;
                }
            }
            
            if (!collisionHandled) {
                stack.push_back(asteroid);
            }
        }

        return stack;
    }
};
