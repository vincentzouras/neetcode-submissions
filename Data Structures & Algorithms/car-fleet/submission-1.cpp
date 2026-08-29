class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int, int>> cars; 
        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end(), [](pair<int, int> a, pair<int, int> b) { 
            return a.first > b.first; });
        
        stack<double> s;
        for (int i = 0; i < n; i++) {
            double time = (double) (target - cars[i].first) / cars[i].second;
            if (!s.empty() && time <= s.top()) continue;
            s.push(time);
        }

        return s.size();
    }
};
