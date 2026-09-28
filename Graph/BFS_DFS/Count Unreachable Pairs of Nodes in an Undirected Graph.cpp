/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=kOt2VNsU0FE
      Company Tags                : MICROSOFT
      Leetcode Link               : https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
*/


//Approach-1 : Using DFS - (Remaining Nodes concept)
class Solution {
public:
    
    void dfs(int u, unordered_map<int, vector<int>> &adj, vector<bool>& visited, long long &sizeOfComponent) {
        visited[u] = true;
        sizeOfComponent++;
        
        for(int &v : adj[u]) {
            
            if(!visited[v]) {
                dfs(v, adj, visited, sizeOfComponent);
            }
            
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        
        for(auto &vec : edges) {
            
            int u = vec[0];
            int v = vec[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(n, false);
        long long remainingNodes = n;
        
        long long result = 0;
        
        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                
                long long sizeOfComponent = 0;
                
                dfs(i, adj, visited, sizeOfComponent);
                
                result += (sizeOfComponent) * (remainingNodes-sizeOfComponent);
                
                remainingNodes -= sizeOfComponent;
                
            }
        }
        
        return result;
    }
};


//Approach-2 : Using DFS (Calculating duplicates and divide by 2)
class Solution {
public:
    
    void dfs(int u, unordered_map<int, vector<int>> &adj, vector<bool>& visited, long long &sizeOfComponent) {
        visited[u] = true;
        sizeOfComponent++;
        
        for(int &v : adj[u]) {
            
            if(!visited[v]) {
                dfs(v, adj, visited, sizeOfComponent);
            }
            
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        
        for(auto &vec : edges) {
            
            int u = vec[0];
            int v = vec[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(n, false);
        
        long long result = 0;
        
        for(int i = 0; i<n; i++) {
            if(!visited[i]) {
                
                long long sizeOfComponent = 0;
                
                dfs(i, adj, visited, sizeOfComponent);
                
                result += (sizeOfComponent) * (n-sizeOfComponent);
                
            }
        }
        
        return result/2;
    }
};

//Approach-3 : Using BFS 
class Solution {
public:
    
    void bfs(int u, unordered_map<int, vector<int>> &adj, vector<bool>& visited, long long &Size) {
        
        queue<int> que;
        que.push(u);
        
        visited[u] = true;
        Size++;
        
        while(!que.empty()) {
            
            int x = que.front();
            que.pop();
            
            for(int &v : adj[x]) {
                
                if(!visited[v]) {
                    visited[v] = true;
                    que.push(v);
                    Size++;
                }
                
            }
            
        }
        
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        unordered_map<int, vector<int>> adj;
        
        for(auto &vec : edges) {
            
            int u = vec[0];
            int v = vec[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        
        vector<bool> visited(n, false);
        
        long long remainingNodes = n;
        
        long long result = 0;
        
        for(int i = 0; i<n; i++) {
            
            if(!visited[i]) {
                
                long long Size = 0;
                
                bfs(i, adj, visited, Size);
                
                result += (Size) * (remainingNodes - Size);
                
                remainingNodes -= Size;
            }
            
        }
        
        return result;
        
    }
};


//Approach - 4 : DSU (In mo DS repo - Link below)
//https://github.com/MAZHARMIK/Interview_DS_Algo/blob/master/Graph/Disjoint%20Set/Count%20Unreachable%20Pairs%20of%20Nodes%20in%20an%20Undirected%20Graph.cpp

//JAVA

// Approach 1 — DFS (Remaining Nodes)
class Solution {
    void dfs(int u, Map<Integer, List<Integer>> adj, boolean[] visited, long[] sizeOfComponent) {
        visited[u] = true;
        sizeOfComponent[0]++;

        for (int v : adj.getOrDefault(u, new ArrayList<>())) {
            if (!visited[v])
                dfs(v, adj, visited, sizeOfComponent);
        }
    }

    public long countPairs(int n, int[][] edges) {
        Map<Integer, List<Integer>> adj = new HashMap<>();

        for (int[] vec : edges) {
            int u = vec[0];
            int v = vec[1];

            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(u);
        }

        boolean[] visited = new boolean[n];
        long remainingNodes = n;
        long result = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                long[] sizeOfComponent = {0};

                dfs(i, adj, visited, sizeOfComponent);

                result += sizeOfComponent[0] * (remainingNodes - sizeOfComponent[0]);
                remainingNodes -= sizeOfComponent[0];
            }
        }

        return result;
    }
}
// Approach 2 — DFS (Duplicates / 2)
class Solution {
    void dfs(int u, Map<Integer, List<Integer>> adj, boolean[] visited, long[] sizeOfComponent) {
        visited[u] = true;
        sizeOfComponent[0]++;

        for (int v : adj.getOrDefault(u, new ArrayList<>())) {
            if (!visited[v])
                dfs(v, adj, visited, sizeOfComponent);
        }
    }

    public long countPairs(int n, int[][] edges) {
        Map<Integer, List<Integer>> adj = new HashMap<>();

        for (int[] vec : edges) {
            int u = vec[0];
            int v = vec[1];

            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(u);
        }

        boolean[] visited = new boolean[n];
        long result = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                long[] sizeOfComponent = {0};

                dfs(i, adj, visited, sizeOfComponent);

                result += sizeOfComponent[0] * (n - sizeOfComponent[0]);
            }
        }

        return result / 2;
    }
}
// Approach 3 — BFS
class Solution {
    void bfs(int u, Map<Integer, List<Integer>> adj, boolean[] visited, long[] Size) {
        Queue<Integer> que = new LinkedList<>();
        que.offer(u);

        visited[u] = true;
        Size[0]++;

        while (!que.isEmpty()) {
            int x = que.poll();

            for (int v : adj.getOrDefault(x, new ArrayList<>())) {
                if (!visited[v]) {
                    visited[v] = true;
                    que.offer(v);
                    Size[0]++;
                }
            }
        }
    }

    public long countPairs(int n, int[][] edges) {
        Map<Integer, List<Integer>> adj = new HashMap<>();

        for (int[] vec : edges) {
            int u = vec[0];
            int v = vec[1];

            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(u);
        }

        boolean[] visited = new boolean[n];
        long remainingNodes = n;
        long result = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                long[] Size = {0};

                bfs(i, adj, visited, Size);

                result += Size[0] * (remainingNodes - Size[0]);
                remainingNodes -= Size[0];
            }
        }

        return result;
    }
}
// Complexity

// For all 3 approaches:

// Time: O(V + E)
// Space: O(V + E)
// Since we traverse every node and edge once.

// Approach 1 and BFS use the remaining nodes concept, so we don't need /2.
// Approach 2 counts every valid pair twice, so we return result / 2.

// DSU
// Approach 4 — DSU / Union Find

// Keeping the same variable names:

class Solution {
    int[] parent;
    int[] rank;

    int find(int x) {
        if (x == parent[x])
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent)
            return;

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[y_parent] = x_parent;
            rank[x_parent]++;
        }
    }

    public long countPairs(int n, int[][] edges) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }

        for (int[] vec : edges) {
            int u = vec[0];
            int v = vec[1];

            Union(u, v);
        }

        Map<Integer, Long> size = new HashMap<>();

        for (int i = 0; i < n; i++) {
            int root = find(i);
            size.put(root, size.getOrDefault(root, 0L) + 1);
        }

        long result = 0;
        long remainingNodes = n;

        for (long Size : size.values()) {
            result += Size * (remainingNodes - Size);
            remainingNodes -= Size;
        }

        return result;
    }
// }
// Complexity
// Time: O((V + E) α(V)) ≈ O(V + E)
// Space: O(V)
