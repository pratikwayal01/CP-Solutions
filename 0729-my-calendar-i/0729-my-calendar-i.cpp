class MyCalendar {
public:
    vector<pair<int, int>> events;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for (auto& event : events) {
            int s = event.first;
            int e = event.second;
            
            if (!(end <= s || start >= e)) {
                return false; 
            }
        }
        events.push_back({start, end}); 
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */