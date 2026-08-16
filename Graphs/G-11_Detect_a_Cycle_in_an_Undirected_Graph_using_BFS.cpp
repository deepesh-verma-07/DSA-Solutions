class Solution {
private:
    // Helper function to perform BFS and detect cycle in a single component
    bool detect(int src, vector<int> adj[], int vis[]) {
        vis[src] = 1;
        queue<pair<int, int>> q; // Store {current_node, parent_node}
        
        q.push({src, -1});

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            // Traverse through all adjacent neighbors
            for (auto adjacentNode : adj[node]) {
                // Case 1: If adjacent node is not visited yet
                if (!vis[adjacentNode]) {
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                }
                // Case 2: If adjacent node is visited and it's NOT the parent
                else if (parent != adjacentNode) {
                    return true; // Cycle found
                }
            }
        }
        return false; // No cycle found in this component
    }

public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};

        // Check for all components (Handles disconnected graphs)
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (detect(i, adj, vis)) return true;
            }
        }
        return false;
    }
};
