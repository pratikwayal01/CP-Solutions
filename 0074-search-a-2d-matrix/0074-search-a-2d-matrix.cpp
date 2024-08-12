class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start =0;
        int m=matrix.size();
        int n=matrix[0].size();
        int end=m*n-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            int i=mid/n;
            int j=mid%n;
            if(matrix[i][j]==target){
                return true;
            }
            else if(matrix[i][j]<target){
                start=mid+1;
            }
            else {
                end=mid-1;
            }

        }
        return false;
    }
};