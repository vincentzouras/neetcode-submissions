class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // build freq map
        unordered_map<int, int> freqs; // num, freq
        for (int num : nums) {
            freqs[num]++;
        }

        // convert to list of pairs 
        vector<pair<int, int>> pairs(freqs.begin(), freqs.end());

        // sort pairs by second element descending
        sort(pairs.begin(), pairs.end(), 
            [](auto &a, auto &b) { 
                return a.second > b.second; 
            }
        );

        vector<int> result;
        for (int i = 0; i < k && i < pairs.size(); i++){
            result.push_back(pairs[i].first);
        }

        return result;

        /*
        build map: O(n)
        convert to list: O(m) where m = n in worst case
        sort pairs: O(n log n) since worst case m was n 
        total: O(n log n)
        */
    }
};
