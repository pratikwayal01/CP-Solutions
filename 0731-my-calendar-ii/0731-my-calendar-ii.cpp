class MyCalendarTwo {
public:
    std::vector<std::pair<int, int>> non_overlapping;
    std::vector<std::pair<int, int>> overlapping;
    MyCalendarTwo() {}

    bool book(int start, int end) {
        for (const auto& overlap : overlapping) {
            int overlap_start = overlap.first;
            int overlap_end = overlap.second;
            if (start < overlap_end && end > overlap_start) {
                return false;
            }
        }

        for (const auto& interval : non_overlapping) {
            int interval_start = interval.first;
            int interval_end = interval.second;
            if (start < interval_end && end > interval_start) {
                overlapping.push_back({max(start, interval_start),min(end, interval_end)});
            }
        }

        non_overlapping.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */