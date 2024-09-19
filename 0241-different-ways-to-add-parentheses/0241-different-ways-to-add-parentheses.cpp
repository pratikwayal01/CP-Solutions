class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        int n = expression.size();
        for (int i = 0; i < n; i++) {
            char op = expression[i];
            if (op == '+' || op == '-' || op == '*') {
              
                vector<int> x = diffWaysToCompute(expression.substr(0, i));
                vector<int> y = diffWaysToCompute(expression.substr(i + 1));

                for (int a : x) {
                    for (int b : y) {
                        if (op == '+') res.push_back(a + b);
                        else if (op == '-') res.push_back(a - b);
                        else if (op == '*') res.push_back(a * b);
                    }
                }
            }
        }
        
        if (res.empty()) res.push_back(stoi(expression));
        return res;
    }
};