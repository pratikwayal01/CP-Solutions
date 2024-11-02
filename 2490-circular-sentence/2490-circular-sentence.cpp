class Solution {
public:
    bool isCircularSentence(string sentence) {
        stringstream ss(sentence);
        vector<string> words;
        string word;

        while (ss >> word) {
            words.push_back(word);
        }

        int n = words.size();
        for (int i = 0; i < n; ++i) {
            char lastChar = words[i].back();
            char nextFirstChar = words[(i + 1) % n].front();

            if (lastChar != nextFirstChar) {
                return false;
            }
        }

        return true;
    }
};