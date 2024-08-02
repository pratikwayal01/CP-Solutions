class Solution {
public:
    bool isSubsequence(string s, string t) {
        int count=0;
        int a=s.length();
        int b=t.length();
        if(a>b){
            return false;
        }
        for(int i=0;i<b;i++){
            if(s[count]==t[i]){
                count++;
            }
        }
        return count==s.length();
    }
};