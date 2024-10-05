class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp1, mp2;

        for (char c : s1) {
            mp1[c]++;
        }

        int Size = s1.length();
        int n = s2.length();

        if (Size > n) {
            return false;
        }

        for (int i = 0; i < Size; i++) {
            mp2[s2[i]]++;
        }

        if (mp1 == mp2){
            return true;
        }

        for (int i = Size; i < n; i++) {
            mp2[s2[i - Size]]--;
            if (mp2[s2[i - Size]] == 0) {
                mp2.erase(s2[i - Size]);
            }
            mp2[s2[i]]++;
            if (mp1 == mp2)
                return true;
        }
        return false;
    }
};