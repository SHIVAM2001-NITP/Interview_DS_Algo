/*
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=qSBvKlUq0xo
      Company Tags                : Microsoft
      Leetcode Link               : https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
*/

//DFS - O(V+E) - We visit all nodes and edges in the graph
class Solution {
public:
    
    int DFS(unordered_map<int, vector<int>> &adj, int curr, int parent, vector<bool>& hasApple) {
        int time = 0;
        
        for(int &child : adj[curr]) {
            if(child == parent)
                continue;
            int time_from_bachha_log = DFS(adj, child, curr, hasApple); 
              
            if(time_from_bachha_log || hasApple[child])
                time += 2 + time_from_bachha_log;  
        }
        return time;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int, vector<int>> adj;
        for(auto &vec : edges) {
            int u = vec[0];
            int v = vec[1]; 
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        return DFS(adj, 0, -1, hasApple);
    }
};
//Java

class Solution {
    int DFS(Map<Integer, List<Integer>> adj, int curr, int parent, List<Boolean> hasApple) {
        int time = 0;
        for (int child : adj.getOrDefault(curr, new ArrayList<>())) {
            if (child == parent)
                continue;

            int timeFromChild = DFS(adj, child, curr, hasApple);

            if (timeFromChild > 0 || hasApple.get(child))
                time += 2 + timeFromChild;
        }

        return time;
    }

    public int minTime(int n, int[][] edges, List<Boolean> hasApple) {
        Map<Integer, List<Integer>> adj = new HashMap<>();

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(v);
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(u);
        }

        return DFS(adj, 0, -1, hasApple);
    }
}

//Complexity:Time O(V + E) , 
//Space O(V) recursion + adjacency-list space.
