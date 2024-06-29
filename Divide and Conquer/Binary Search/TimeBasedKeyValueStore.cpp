/**
 * Design a time-based key-value data structure that can store multiple values for the same key 
 * at different time stamps and retrieve the key's value at a certain timestamp.
 * 
 * Implement the TimeMap class:
 * TimeMap() Initializes the object of the data structure.
 * void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
 * String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".
 * 
 * Example 1:
 * Input
 * ["TimeMap", "set", "get", "get", "set", "get", "get"]
 * [[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
 * 
 * Output
 * [null, null, "bar", "bar", null, "bar2", "bar2"]
 * 
 * Explanation
 * TimeMap timeMap = new TimeMap();
 * timeMap.set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
 * timeMap.get("foo", 1);         // return "bar"
 * timeMap.get("foo", 3);         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
 * timeMap.set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
 * timeMap.get("foo", 4);         // return "bar2"
 * timeMap.get("foo", 5);         // return "bar2"
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        key_value_time_map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        // check if the key exists or not
        if (!key_value_time_map.contains(key))
            return "";
        
        // if request timestamp is lesser than the lowest timestamp for a given key
        // then there's no candidate.
        // Return
        if (timestamp < key_value_time_map[key][0].first)
            return "";
        
        // Binary search on the value pair
        int left = 0;
        int right = key_value_time_map[key].size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (key_value_time_map[key][mid].first == timestamp) {
                // exact required timestamp found
                // mid is the candidate
                // return
                return key_value_time_map[key][mid].second;
            } else if (key_value_time_map[key][mid].first < timestamp) {
                // current timestamp is < required timestamp
                // eliminate the left seach space
                // since we want the largest timestamp_prev
                // but, store the current candidate
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // if no match 
        return (result == -1) ? "" : key_value_time_map[key][result].second;
    }

private:
    unordered_map<string, vector<pair<int, string>>> key_value_time_map;
};

int main() {
    TimeMap timeMap;
    timeMap.set("foo", "bar", 1);
    cout << timeMap.get("foo", 1) << endl;
    cout << timeMap.get("foo", 3) << endl;
    timeMap.set("foo", "bar2", 4);
    cout << timeMap.get("foo", 4) << endl;
    cout << timeMap.get("foo", 5) << endl;
    return 0;
}