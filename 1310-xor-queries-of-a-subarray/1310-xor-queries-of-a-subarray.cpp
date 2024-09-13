class Solution {
public:
   vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    vector<int> res;
    vector<int> xorr(arr.size() + 1, 0);
    for (int i = 0; i < arr.size(); i++) {
        xorr[i + 1] = xorr[i] ^ arr[i];
    }
    for (auto& q : queries) {
        int left = q[0], right = q[1];
        res.push_back(xorr[left] ^ xorr[right + 1]);
    }

    return res;
   }
};