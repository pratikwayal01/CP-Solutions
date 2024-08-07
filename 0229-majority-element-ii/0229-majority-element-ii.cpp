class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>mpp;
        vector<int>ans;
        int n=nums.size();
        for(auto x:nums){
            mpp[x]++;
        }
        for(auto pair :mpp){
            if(pair.second>n/3){
                ans.push_back(pair.first);
            }
        }
        return ans;
    }
};