class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int countL = 0;
    int countR = 0;
    int count_ = 0;

    for (char move : moves) {
        if (move == 'L') {
            countL++;
        } else if (move == 'R') {
            countR++;
        } else if (move == '_') {
            count_++;
        }
    }

    return abs(countL - countR) + count_;
    }
};