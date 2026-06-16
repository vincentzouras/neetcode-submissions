class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;

        // init with all UNIQUE chars
        for (const string &word : words) {
            for (char c : word) {
                indegree[c] = 0;
            }
        }

        // build graph
        for (int i = 0; i < words.size() - 1; i++) {
            const string& word = words[i];
            const string& next_word = words[i + 1];

            // Edge case: ["abc","ab"]
            if (word.size() > next_word.size() && 
                word.substr(0, next_word.size()) == next_word) 
                return "";
            
            int min_len = min(word.size(), next_word.size());
            for (int j = 0; j < min_len; j++) {
                if (word[j] != next_word[j]) {
                    char u = word[j];
                    char v = next_word[j];

                    if (!adj[u].contains(v)) {
                        adj[u].insert(v);
                        indegree[v]++;
                    }

                    break; // only first difference tells us order
                }
            }
        }

        // topological sort 
        queue<char> q;
        for (auto const& [node, deg] : indegree) { 
            if (deg == 0) q.push(node);
        }

        string result = "";
        while (!q.empty()) { 
            char curr = q.front();
            q.pop();
            result += curr;

            for (char neighbor : adj[curr]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) q.push(neighbor);
            }
        }

        if (result.size() != indegree.size()) return "";

        return result;
    }
};
