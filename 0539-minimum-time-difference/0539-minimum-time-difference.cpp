class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
    vector<int> minutes;
    for(const auto& time : timePoints) {
        int hour = stoi(time.substr(0, 2));
        int min = stoi(time.substr(3, 2));
        minutes.push_back(hour * 60 + min);
    }
    sort(minutes.begin(), minutes.end());
    int size = minutes.size();
    int minDiff = INT_MAX;
    for(int i = 1; i < size; ++i) {
        minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
    }

    minDiff = min(minDiff, 1440 + minutes[0] - minutes.back());
    
    return minDiff;
}

};