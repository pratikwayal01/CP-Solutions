class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> ans(k, 0);
    
    for (int num : arr) {
        int rem = (num % k + k) % k;  
        ans[rem]++;
    }


    for (int i = 1; i < k; ++i) {
        if (ans[i] != ans[k - i]) {
            return false;
        }
    }


    return ans[0] % 2 == 0;
    }
};