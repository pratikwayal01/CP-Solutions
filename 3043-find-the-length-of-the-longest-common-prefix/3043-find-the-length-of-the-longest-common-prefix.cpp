class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> st;
        for (int num1 : arr1) {
            string str1 = to_string(num1);
            for (int len = 1; len <= str1.size(); ++len) {
                st.insert(str1.substr(0, len));
            }
        }
        int maxi = 0;
        for (int num2 : arr2) {
            string str2 = to_string(num2);
            for (int len = 1; len <= str2.size(); ++len) {
                string prefix = str2.substr(0, len);
                if (st.count(prefix)) {
                    maxi = max(maxi, len);
                }
            }
        }
        return maxi;
    }
};