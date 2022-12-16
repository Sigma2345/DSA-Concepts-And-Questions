// https://leetcode.com/problems/time-based-key-value-store/


class TimeMap {
public:
    unordered_map<string, unordered_map<int, string>> keyTimeMap;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        keyTimeMap[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        // If the 'key' does not exist in map we will return empty string.
        if (!keyTimeMap.count(key)) {
            return "";
        }
        
        for (int currTime = timestamp; currTime >= 1; --currTime) {
            // get max value >= 1 that satisfies  given conditions
            if (keyTimeMap[key].count(currTime)) {
                return keyTimeMap[key][currTime];
            }
        }
        
            // Otherwise no time <= timestamp was stored in key's bucket.
            return "";
    }
};
