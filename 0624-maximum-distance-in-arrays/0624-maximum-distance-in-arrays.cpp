class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
    int mini = arrays[0].front(); 
    int maxi = arrays[0].back();  
    int dist = 0;
    for (int i = 1; i < arrays.size(); ++i) {
        dist = max(dist, abs(arrays[i].back() - mini));
        dist = max(dist, abs(maxi - arrays[i].front()));
        mini = min(mini, arrays[i].front());
        maxi = max(maxi, arrays[i].back());
    }

    return dist;
    }
};