class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir = 0; 

        unordered_set<string> obstacleSet;
        for (const auto& obstacle : obstacles) {
            obstacleSet.insert(to_string(obstacle[0]) + "_" + to_string(obstacle[1]));
        }

        int x = 0, y = 0;
        int maxDist = 0;

        for (int command : commands) {
            if (command == -2) {
                dir = (dir + 3) % 4;
            } else if (command == -1) {
                dir = (dir + 1) % 4;
            } else {
                for (int i = 0; i < command; ++i) {
                    int nx = x + directions[dir].first;
                    int ny = y + directions[dir].second;
                    if (obstacleSet.find(to_string(nx) + "_" + to_string(ny)) != obstacleSet.end()) {
                        break; 
                    }
                    x = nx;
                    y = ny;

                    maxDist = max(maxDist, x * x + y * y);
                }
            }
        }

        return maxDist; 
    }
};