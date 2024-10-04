class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(), skill.end());
        long long target = skill[0] + skill[n - 1]; 
        long long Product = 0;
        for (int i = 0; i < n / 2; i++) {
            long long Sum = skill[i] + skill[n - i - 1];
            if (Sum != target) {
                return -1;
            }
            Product += skill[i] * skill[n - i - 1];
        }
        return Product; 
    }
};