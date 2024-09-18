class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans;
        sort(nums.begin(),nums.end(),[](int a,int b){
            return to_string(a)+ to_string(b) > to_string(b) + to_string(a);
        });
        for(auto i:nums){
            ans +=to_string(i);
        }
        return ans[0]=='0' ? "0": ans;
    }
};