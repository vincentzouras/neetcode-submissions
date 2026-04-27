class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        // count frequencies
        unordered_map<int, int> freqs; // num: freq
        for (int num : nums) {
            freqs[num]++;
        }

        // create buckets
        vector<vector<int>> buckets(n + 1); // index 1 to n
        for (auto &p : freqs) {
            int num = p.first;
            int freq = p.second;
            buckets[freq].push_back(num); 
        }

        // iterate from highest possible frequency down to collect top k
        vector<int> result;
        for (int i = n; i >= 0; i--) {
            vector<int> bucket = buckets[i];

            for (int num: bucket) {
                if (result.size() == k) return result;
                result.push_back(num);
            }
        }

        return result;
    }
};
