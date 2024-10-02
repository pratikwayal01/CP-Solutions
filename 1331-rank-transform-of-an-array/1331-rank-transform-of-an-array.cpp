class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        sort(arr.begin(), arr.end());
        map<int, int> mpp;
        int rank = 1;
        for (int num : arr) {
            if (mpp.find(num) == mpp.end()) {
                mpp[num] = rank;
                rank++;
            }
        }
        vector<int> ans;
        for (int num : temp) {
            ans.push_back(mpp[num]);
        }
        return ans;
    }
};