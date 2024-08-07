class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        int temp[n];
        int j=0;
        int k=1;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                temp[j]=nums[i];
                j+=2;
            }
            if(nums[i]<0){
                temp[k]=nums[i];
                k+=2;
            }
        }

        for(int i=0;i<n;i++){
           ans.push_back(temp[i]);
        }
        
         return ans;
        
    }
};