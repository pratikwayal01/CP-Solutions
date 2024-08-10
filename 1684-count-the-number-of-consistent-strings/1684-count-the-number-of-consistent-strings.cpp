class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count=0;
        for(int i=0;i<words.size();i++){
            string s=words[i];
            bool flag=true;
            for(int j=0;j<s.length();j++){
               if (allowed.find(s[j]) == std::string::npos) {
                flag = false;
                break;
            }
            }
            if(flag){
                count++;
            }
        }
        return count;
    }
};