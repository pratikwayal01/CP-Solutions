class Solution {
public:
    static bool parseBoolExpr(string& expr) {
        vector<char> stack;
        stack.reserve(expr.size()); 
        

        for (char c : expr) {
            switch (c) {
            case ',':  
                break;
            case ')': {  
                char s; 
                vector<char> x;
                char t = stack.back();
                x.push_back(t);
                stack.pop_back();
                while (t != '(') {
                    t = stack.back();
                    stack.pop_back();
                    if (t != '(') {
                        x.push_back(t); 
                    }
                }
                

                char op = stack.back();
                stack.pop_back();
                switch (op) {
                case '!':  
                    s = (x[0] == 'f') ? 't' : 'f';
                    break;
                case '&':  
                    s = all_of(x.begin(), x.end(), [](char b) { return b == 't'; }) ? 't' : 'f';
                    break;
                case '|': 
                    s = any_of(x.begin(), x.end(), [](char b) { return b == 't'; }) ? 't' : 'f';
                    break;
                }
                
                stack.push_back(s);  
                break;
            }
            default:  
                stack.push_back(c);
            }
        }
        
        return stack.back() == 't';
    }
};


auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
