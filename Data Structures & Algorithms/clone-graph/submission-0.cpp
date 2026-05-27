/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> hashmap;
    Node* dfs(Node* curr) {
        if (!curr) return nullptr;
        if (hashmap.contains(curr)) return hashmap[curr]; 

        Node* new_node = new Node(curr->val); 
        hashmap[curr] = new_node;

        for (Node* neighbor : curr->neighbors) {
            Node* new_neighbor = dfs(neighbor);
            new_node->neighbors.push_back(new_neighbor);
        }

        return new_node;
    }
    Node* cloneGraph(Node* node) {
        return dfs(node);
    }
};
