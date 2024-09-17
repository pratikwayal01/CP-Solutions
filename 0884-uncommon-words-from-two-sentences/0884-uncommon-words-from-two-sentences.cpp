class Solution {
public:
    map<string, int> mpp;

    void stringstreeam(string s) {
        stringstream st(s);
        string word;
        while (st >> word)
            mpp[word]++;
    }
    vector<string> uncommonFromSentences(string s1, string s2) {
        stringstreeam(s1);
        stringstreeam(s2);
        vector<string> res;

        for (auto i : mpp) {
            if (i.second == 1) {
                res.push_back(i.first);
            }
        }
        return res;
    }
};