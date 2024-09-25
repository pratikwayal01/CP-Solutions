
// I will learn Trie soon
struct TrieNode {
    TrieNode* children[26] = {};
    int score = 0;
};

class Trie {
public:
    TrieNode* root;

    Trie() { root = new TrieNode(); }

    void insert(const string& word) {
        TrieNode* node = root;
        for (const char& ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
            node->score++;
        }
    }

    int getScore(const string& word) {
        TrieNode* node = root;
        int totalScore = 0;
        for (const char& ch : word) {
            int idx = ch - 'a';
            node = node->children[idx];
            totalScore += node->score;
        }
        return totalScore;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        for (const auto& word : words) {
            trie.insert(word);
        }
        vector<int> result;
        for (const auto& word : words) {
            result.push_back(trie.getScore(word));
        }
        return result;
    }
};