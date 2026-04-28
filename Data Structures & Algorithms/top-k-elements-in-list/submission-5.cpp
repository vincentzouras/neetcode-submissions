class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size(); 

        // count frequency of each num
        unordered_map<int, int> freqs; // num, freq
        for (const int &num : nums) {
            freqs[num]++;
        }

        // create buckets 
        vector<vector<int>> buckets(n + 1); // potentially accessing index n when all nums are same 
        for (auto p : freqs) {
            buckets[p.second].push_back(p.first); // push num to bucket vector for each freq
        }

        vector<int> result; 
        for (int i = n; i > 0; i--) {
            vector<int> bucket = buckets[i];
            for (int num : bucket) {
                if (result.size() == k) return result;
                result.push_back(num);
            }
        }

        return result;
    }
};
