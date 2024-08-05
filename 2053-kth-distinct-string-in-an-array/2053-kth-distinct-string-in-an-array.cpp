class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
    unordered_map<string, int> mpp;
    for (const string& s : arr) {
        mpp[s]++;
    }

    for (const string& s : arr) {
        if (mpp[s] == 1) {
            k--;
            if (k == 0) {
                return s;
            }
        }
    }
    
    return "";
    }
};