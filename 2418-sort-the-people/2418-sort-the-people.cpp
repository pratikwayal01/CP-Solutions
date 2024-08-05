class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    map<int, string> mpp;
    for (int i = 0; i < names.size(); ++i) {
        mpp[heights[i]] = names[i];
    }

    vector<string> arr;
    for (auto it = mpp.rbegin(); it != mpp.rend(); ++it) {
        arr.push_back(it->second);
    }

    return arr;
    }
};