class Solution {
public:
    struct Comparator {
        bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
            return a.second > b.second; // does a have lower priority than b? (for pq)
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // count frequencies
        unordered_map<int, int> freqs; // num, freq
        for (int num : nums) {
            freqs[num]++;
        }

        // insert into min heap
        // smallest on top, so when full we remove top, leaves us with largest
        priority_queue<
            pair<int, int>, // element type
            vector<pair<int, int>>, // container
            Comparator // ordering rule
        > min_heap;
        for (auto &p : freqs) {
            min_heap.push(p);
            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }

        // make vector from first elements in heap pairs
        vector<int> result; 
        while (!min_heap.empty()) {
            result.push_back(min_heap.top().first);
            min_heap.pop();
        }

        return result;

        /*
        min heap improves time complexity to O(n log k)

        We do m unique element insertions into a heap restricted to k height
        so O(m log k)
        But worst case, the num of unique elements m = n the num of elements total
        which gives us O(n log k)
        */
    }
};
