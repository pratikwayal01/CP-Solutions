class Solution {
public:
    int minLength(string s) {
       stack<char> stk;
    for (auto i : s) {
        if (!stk.empty() && ((stk.top() == 'A' && i == 'B') || (stk.top() == 'C' && i == 'D'))) {
            stk.pop();  
        } 
        else {
            stk.push(i); 
        }
    }
    return stk.size();
    }
};