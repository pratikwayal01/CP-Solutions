class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> result;
        string root = "";

        for (auto f : folder) {
            if (root.empty() || f.find(root + "/") != 0) {
                result.push_back(f);
                root = f;  
            }
        }
        return result;  
    }
};