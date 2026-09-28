/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=blUPwDof-r4
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/
*/

                                    /*LEETCODE WEEKLY CONTEST - 322*/

//DFS
class Solution {
public:

    void dfs(unordered_map<int, vector<pair<int, int>>> &adj, int u, vector<bool>& visited, int &result) {
        
        visited[u] = true;
        
        for(auto &vec : adj[u]) {
            int v = vec.first;
            int c = vec.second;
            
            result = min(result, c);
            
            if(!visited[v]) {
                dfs(adj, v, visited, result);
            }
        }
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> adj;
        
        for(auto &vec : roads) {
            
            int u = vec[0];
            int v = vec[1];
            int c = vec[2];
            
            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
        }
        
        vector<bool> visited(n, false);
        int result = INT_MAX;
        dfs(adj, 1, visited, result);
        
        return result;
    }
};

//BFS soon
//Also, Union Find approach will be provided soon in Union Find sub-repo

//JAVA
class Solution {
    void dfs(Map<Integer, List<int[]>> adj, int u, boolean[] visited, int[] result) {
        visited[u] = true;

        for (int[] vec : adj.getOrDefault(u, new ArrayList<>())) {
            int v = vec[0];
            int c = vec[1];

            result[0] = Math.min(result[0], c);

            if (!visited[v])
                dfs(adj, v, visited, result);
        }
    }

    public int minScore(int n, int[][] roads) {
        Map<Integer, List<int[]>> adj = new HashMap<>();

        for (int[] vec : roads) {
            int u = vec[0];
            int v = vec[1];
            int c = vec[2];

            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(new int[]{v, c});
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(new int[]{u, c});
        }

        boolean[] visited = new boolean[n + 1];
        int[] result = {Integer.MAX_VALUE};

        dfs(adj, 1, visited, result);

        return result[0];
    }
}
// Complexity
// Time: O(V + E)
// Space: O(V + E) — adjacency list + visited array + recursion stack.

class Solution {
    void bfs(Map<Integer, List<int[]>> adj, int u, boolean[] visited, int[] result) {
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(u);
        visited[u] = true;

        while (!queue.isEmpty()) {
            u = queue.poll();

            for (int[] vec : adj.getOrDefault(u, new ArrayList<>())) {
                int v = vec[0];
                int c = vec[1];

                result[0] = Math.min(result[0], c);

                if (!visited[v]) {
                    visited[v] = true;
                    queue.offer(v);
                }
            }
        }
    }

    public int minScore(int n, int[][] roads) {
        Map<Integer, List<int[]>> adj = new HashMap<>();

        for (int[] vec : roads) {
            int u = vec[0];
            int v = vec[1];
            int c = vec[2];

            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(new int[]{v, c});
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(new int[]{u, c});
        }

        boolean[] visited = new boolean[n + 1];
        int[] result = {Integer.MAX_VALUE};

        bfs(adj, 1, visited, result);

        return result[0];
    }
}

// Complexity:
// Time: O(V + E)
// Space: O(V + E)

//DSU
class Solution {
    int[] parent;
    int[] rank;

    int find(int u) {
        if (u == parent[u])
            return u;

        return parent[u] = find(parent[u]);
    }

    void Union(int u, int v) {
        int u_parent = find(u);
        int v_parent = find(v);

        if (u_parent == v_parent)
            return;

        if (rank[u_parent] > rank[v_parent]) {
            parent[v_parent] = u_parent;
        } else if (rank[u_parent] < rank[v_parent]) {
            parent[u_parent] = v_parent;
        } else {
            parent[v_parent] = u_parent;
            rank[u_parent]++;
        }
    }

    public int minScore(int n, int[][] roads) {
        parent = new int[n + 1];
        rank = new int[n + 1];

        for (int i = 1; i <= n; i++)
            parent[i] = i;

        for (int[] vec : roads) {
            int u = vec[0];
            int v = vec[1];

            Union(u, v);
        }

        int result = Integer.MAX_VALUE;

        int root = find(1);

        for (int[] vec : roads) {
            int u = vec[0];
            int v = vec[1];
            int c = vec[2];

            if (find(u) == root && find(v) == root)
                result = Math.min(result, c);
        }

        return result;
    }
}
// Idea
// Unlike DFS/BFS, we first connect all cities using DSU.
// After that:
// int root = find(1);
// gives the connected component containing city 1.
// Then we check every road:
// if (find(u) == root && find(v) == root)
//     result = Math.min(result, c);

// So we find the minimum road distance among all roads belonging to the component of city 1.
// Complexity
// Time: O((V + E) α(V)) ≈ O(V + E)
// Space: O(V)
