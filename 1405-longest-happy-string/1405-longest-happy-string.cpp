class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string s = "";
        priority_queue<pair<int, char>> pq;

        if (a)
            pq.push({a, 'a'});
        if (b)
            pq.push({b, 'b'});
        if (c)
            pq.push({c, 'c'});

        while (!pq.empty()) {
            int maxCnt = pq.top().first;
            char maxChar = pq.top().second;
            pq.pop();

            if (s.size() >= 2 && s.substr(s.size() - 2) == string(2, maxChar)) {

                if (pq.empty())
                    break;

                int secCnt = pq.top().first;
                char secChar = pq.top().second;
                pq.pop();

                s += secChar;
                secCnt--;

                if (secCnt > 0)
                    pq.push({secCnt, secChar});

                pq.push({maxCnt, maxChar});
            } else {

                s += maxChar;
                maxCnt--;

                if (maxCnt > 0)
                    pq.push({maxCnt, maxChar});
            }
        }

        return s;
    }
};