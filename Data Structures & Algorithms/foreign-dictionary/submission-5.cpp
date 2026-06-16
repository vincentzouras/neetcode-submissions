class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int char_count = 0;

        // track indegrees, init to 0 for each letter present        
        vector<int> indegree(26, -1);
        for (string word : words) {
            for (char c : word) {
                if (indegree[c - 'a'] != 0) char_count++;
                indegree[c - 'a'] = 0;
            }
        }

        // build adjacency list  
        vector<unordered_set<int>> adj(26);
        for (int i = 0; i < words.size() - 1; i++) { 
            string word = words[i];
            string next_word = words[i+1];
            bool different = false;
            int length = min(next_word.size(), word.size());

            for (int j = 0; j < length; j++) {
                if (next_word[j] != word[j]) {
                    different = true;
                    auto p = adj[word[j] - 'a'].insert(next_word[j] - 'a');
                    if (p.second) indegree[next_word[j] - 'a']++;
                    break;
                }
            }

            if (!different && next_word.size() < word.size()) return "";
        }

        // topological sort
        queue<int> q;
        string result;

        for (int i = 0; i < 26; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            result.push_back(node + 'a');

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) q.push(neighbor);
            }
        }

        if (char_count != result.size()) return "";

        return result;
    }
};
