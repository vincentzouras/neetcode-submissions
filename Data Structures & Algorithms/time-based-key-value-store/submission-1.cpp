class TimeMap {
private: 
    unordered_map<string, vector<pair<int, string>>> hashmap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hashmap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>> &valueVector = hashmap[key]; 

        string answer;
        int l = 0;
        int r = valueVector.size()-1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (valueVector[m].first <= timestamp) {
                answer = valueVector[m].second;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return answer; 
    }
};
