// Not my solution 
class Solution {
public:
    bool canChange(string start, string target) {
        if (start.size() != target.size()) {
            return false;
        }
        int n = start.size();

    
        int startL = 0, startR = 0, targetL = 0, targetR = 0;
        for (int i = 0; i < n; ++i) {
            if (start[i] == 'L')
                ++startL;
            if (start[i] == 'R')
                ++startR;
            if (target[i] == 'L')
                ++targetL;
            if (target[i] == 'R')
                ++targetR;
        }

      
        if (startL != targetL || startR != targetR) {
            return false;
        }

        
        int i = 0, j = 0;
        while (i < n && j < n) {
            while (i < n && start[i] == '_')
                ++i;
            while (j < n && target[j] == '_')
                ++j;

            
            if (i >= n || j >= n)
                break;

          
            if (start[i] != target[j]) {
                return false;
            }

           
            if (start[i] == 'L' && i < j) {
                return false; 
                        
            }
            if (start[i] == 'R' && i > j) {
                return false; 
                             
            }
            ++i;
            ++j;
        }

        return true;
    }
};