class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
       unordered_map<char, vector<pair<int, int>>> waiting;
    for (int i = 0; i < words.size(); i++) {
        waiting[words[i][0]].emplace_back(i, 0);
    }

    int count = 0;
    for (char c : s) {
        vector<pair<int, int>> advance = waiting[c];
        waiting[c].clear(); 

        for (auto it : advance) {
            int wordIndex = it.first;
            int charIndex = it.second;
            charIndex++;

            if (charIndex == words[wordIndex].size()) {

                count++;
            } else {
                waiting[words[wordIndex][charIndex]].emplace_back(wordIndex, charIndex);
            }
        }
    }

    return count;
    }
};