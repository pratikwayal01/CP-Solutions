class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
       unordered_map<char,int> mpp;
       for(int i=0;i<magazine.size();i++){
        mpp[magazine[i]]++;
       }
        for (int i = 0; i < ransomNote.size(); i++) {
        if (mpp[ransomNote[i]] > 0) {
            mpp[ransomNote[i]]--;
        } 
        else {
            return false; 
         }
        }
      return true; 
    }
}; 