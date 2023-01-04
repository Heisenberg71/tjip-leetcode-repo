// TC: O(message_size + Dlog(N)) Here, N = max number of element exist in the map;
// MC: O(N)                            D = max number of previously used element should be deleted in each call;

class Logger {
public:
    deque < pair<int, string> > time_string;
    unordered_map <string, int> exist;
    Logger() {
        time_string.clear();
        exist.clear();
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        deleteOldData(timestamp);
        if(exist.count(message)) return 0;
        time_string.push_back({timestamp + 10, message});
        exist[message] = 1;
        return 1;
    }

    void deleteOldData(int tim){
        while(time_string.size() && time_string.front().first <= tim){
            exist.erase(time_string.front().second);
            time_string.pop_front();
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
