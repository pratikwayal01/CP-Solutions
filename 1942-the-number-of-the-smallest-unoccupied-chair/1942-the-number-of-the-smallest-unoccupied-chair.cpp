//not my solution but saved the day
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<pair<int, int>> friends;
        for (int i = 0; i < n; ++i) {
            friends.push_back({times[i][0], i}); 
        }
        sort(friends.begin(), friends.end());

        priority_queue<int, vector<int>, greater<int>> availableChairs;
        for (int i = 0; i < n; ++i) {
            availableChairs.push(i);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>>leaving;


        for (int i = 0; i < n; ++i) {
            int arrival = friends[i].first;
            int friendIdx = friends[i].second;


            while (!leaving.empty() && leaving.top().first <= arrival) {
                availableChairs.push(leaving.top().second);
                leaving.pop();
            }


            int assignedChair = availableChairs.top();
            availableChairs.pop();


            if (friendIdx == targetFriend) {
                return assignedChair;
            }

            leaving.push({times[friendIdx][1], assignedChair});
        }

        return -1; 
    }
};