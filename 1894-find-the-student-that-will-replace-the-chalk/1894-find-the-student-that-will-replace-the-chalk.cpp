class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
       long long chalkSum=0;
       for(auto i:chalk){
        chalkSum +=i;
       }
       k=k%chalkSum;
       for(int i=0;i<chalk.size();i++){
        if(chalk[i]>k){
            return i;
        }
        k=k-chalk[i];
       }
       return 0;
    }
};