/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=42Z0eaopoZ8
      Company Tags                : META
      Leetcode Link               : https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
*/

//DFS - Using Visited Array
class Solution {
public:
    int count = 0;
    void dfs(int node, int parent, vector<vector<pair<int, int>>>& adj, vector<bool>& visited) {
        visited[node] = true;
        
        for (auto& [child, sign] : adj[node]) {
            if (!visited[child]) {
                count += sign;
                dfs(child, node, adj, visited);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& connection : connections) {
            adj[connection[0]].push_back({connection[1], 1});
            adj[connection[1]].push_back({connection[0], 0});
        }
        vector<bool> visited(n, false);
        dfs(0, -1, adj, visited);
        return count;
    }
};

//DFS - Without using Visited Array because there will be no cycle and hence this is undirected graph
class Solution {
public:
    int count = 0;
    void dfs(int node, int parent, vector<vector<pair<int, int>>>& adj) {

        for (auto& [child, sign] : adj[node]) {
            if (child != parent) {
                count += sign;
                dfs(child, node, adj);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& connection : connections) {
            adj[connection[0]].push_back({connection[1], 1});
            adj[connection[1]].push_back({connection[0], 0});
        }
 
        dfs(0, -1, adj);
        return count;
    }
};



//BFS - Soon

//JAVA
// Approach 1 — DFS using visited

// Keeping the same variable names:

class Solution {
    int count = 0;

    void dfs(int node, int parent, List<List<int[]>> adj, boolean[] visited) {
        visited[node] = true;

        for (int[] pair : adj.get(node)) {
            int child = pair[0];
            int sign = pair[1];

            if (!visited[child]) {
                count += sign;
                dfs(child, node, adj, visited);
            }
        }
    }

    public int minReorder(int n, int[][] connections) {
        List<List<int[]>> adj = new ArrayList<>();

        for (int i = 0; i < n; i++)
            adj.add(new ArrayList<>());

        for (int[] connection : connections) {
            adj.get(connection[0]).add(new int[]{connection[1], 1});
            adj.get(connection[1]).add(new int[]{connection[0], 0});
        }

        boolean[] visited = new boolean[n];

        dfs(0, -1, adj, visited);

        return count;
    }
}
// Approach 2 — DFS without visited
// Since the original graph is a tree, there are no cycles. So parent is enough to avoid going back:
class Solution {
    int count = 0;

    void dfs(int node, int parent, List<List<int[]>> adj) {
        for (int[] pair : adj.get(node)) {
            int child = pair[0];
            int sign = pair[1];

            if (child != parent) {
                count += sign;
                dfs(child, node, adj);
            }
        }
    }

    public int minReorder(int n, int[][] connections) {
        List<List<int[]>> adj = new ArrayList<>();

        for (int i = 0; i < n; i++)
            adj.add(new ArrayList<>());

        for (int[] connection : connections) {
            adj.get(connection[0]).add(new int[]{connection[1], 1});
            adj.get(connection[1]).add(new int[]{connection[0], 0});
        }

        dfs(0, -1, adj);

        return count;
    }
}
// Approach 3 — BFS
class Solution {
    int count = 0;

    void bfs(int node, List<List<int[]>> adj, boolean[] visited) {
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(node);
        visited[node] = true;

        while (!queue.isEmpty()) {
            node = queue.poll();

            for (int[] pair : adj.get(node)) {
                int child = pair[0];
                int sign = pair[1];

                if (!visited[child]) {
                    count += sign;
                    visited[child] = true;
                    queue.offer(child);
                }
            }
        }
    }

    public int minReorder(int n, int[][] connections) {
        List<List<int[]>> adj = new ArrayList<>();

        for (int i = 0; i < n; i++)
            adj.add(new ArrayList<>());

        for (int[] connection : connections) {
            adj.get(connection[0]).add(new int[]{connection[1], 1});
            adj.get(connection[1]).add(new int[]{connection[0], 0});
        }

        boolean[] visited = new boolean[n];

        bfs(0, adj, visited);

        return count;
    }
}

// Complexity for all three:
// Time: O(V + E)
// Space: O(V + E)
