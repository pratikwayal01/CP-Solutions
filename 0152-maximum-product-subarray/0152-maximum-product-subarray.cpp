class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double start=1, end=1;
        double product= INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(start==0) start=1;
            if(end==0) end=1;

            start=start*nums[i];
            end=end*nums[nums.size()-i-1];
            product=max(product,max(start,end));
        }
        return product;
    }
};