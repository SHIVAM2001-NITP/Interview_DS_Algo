/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=m6cp4eHWLak
    Company Tags                : <soon>
    Leetcode Link               : https://leetcode.com/problems/longest-cycle-in-a-graph/
*/

//Using DFS (Just using "Cycle Detection in Directed Graph using DFS" code)
class Solution {
public:
    int result = -1;
    
    void dfs(int u, vector<int>& edges, vector<bool> &visited, vector<int>& dist, vector<bool> &inRecursion) {
        
        if(u != -1) {
            
            visited[u] = true;
            inRecursion[u] = true;
            
            int v = edges[u];
            
            if(v != -1 && !visited[v]) {
                
                dist[v] = dist[u] + 1;
                
                dfs(v, edges, visited, dist, inRecursion);

            } else if(v != -1 && inRecursion[v] == true) { //cycle
                
                result = max(result, dist[u] - dist[v] +1);
                
            }
        
            inRecursion[u] = false;
        }
        
    }
    
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        
        
        vector<bool> visited(n, false);
        
        vector<int> dist(n, 1);
        vector<bool> inRecursion(n, false);
        
        for(int i = 0 ; i<n; i++) {
            
            if(!visited[i]) {
                dfs(i, edges, visited, dist, inRecursion);
            }
            
        }
        
        return result;
        
    }
};


//Using BFS - (Kahn's Algo) - Soon

//JAVA
// Java — Using DFS (Cycle Detection in Directed Graph)
class Solution {
    int result = -1;

    void dfs(int u, int[] edges, boolean[] visited, int[] dist, boolean[] inRecursion) {
        if (u != -1) {
            visited[u] = true;
            inRecursion[u] = true;

            int v = edges[u];

            if (v != -1 && !visited[v]) {
                dist[v] = dist[u] + 1;
                dfs(v, edges, visited, dist, inRecursion);
            } else if (v != -1 && inRecursion[v]) { // cycle
                result = Math.max(result, dist[u] - dist[v] + 1);
            }

            inRecursion[u] = false;
        }
    }

    public int longestCycle(int[] edges) {
        int n = edges.length;

        boolean[] visited = new boolean[n];
        int[] dist = new int[n];
        Arrays.fill(dist, 1);
        boolean[] inRecursion = new boolean[n];

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, edges, visited, dist, inRecursion);
            }
        }

        return result;
    }
}

// Complexity
// Time: O(N) — every node is visited once.
// Space: O(N) — visited, dist, inRecursion + recursion stack.
// BFS also
// Java — Using BFS (Kahn's Algorithm)
class Solution {
    public int longestCycle(int[] edges) {
        int n = edges.length;

        int[] indegree = new int[n];

        for (int i = 0; i < n; i++) {
            int v = edges[i];
            if (v != -1)
                indegree[v]++;
        }
        Queue<Integer> que = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                que.offer(i);
        }

        // Remove all nodes which are not part of any cycle
        while (!que.isEmpty()) {
            int u = que.poll();
            int v = edges[u];

            if (v != -1) {
                indegree[v]--;

                if (indegree[v] == 0)
                    que.offer(v);
            }
        }

        // Nodes with indegree > 0 are part of cycles
        int result = -1;
        boolean[] visited = new boolean[n];

        for (int i = 0; i < n; i++) {
            if (indegree[i] > 0 && !visited[i]) {
                int count = 0;
                int u = i;

                while (!visited[u]) {
                    visited[u] = true;
                    count++;
                    u = edges[u];
                }
                result = Math.max(result, count);
            }
        }
        return result;
    }
}
// Idea

// Kahn's Algorithm:

// Calculate indegree of every node.
// Put all nodes with indegree == 0 into the queue.
// Remove them using BFS.
// After BFS, nodes with indegree > 0 must belong to a cycle.
// Traverse each remaining cycle and calculate its length.
// Take the maximum cycle length.
// Complexity
// Time: O(N)
// Space: O(N)
